#include "genome.hpp"
#include "genome_section.hpp"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>

#include "rapidxml/rapidxml.hpp"

using namespace std;

namespace scifir
{
	genome::genome() : chromosomes(),chromosomes_order(),type(),file_name(),xml_file(),species()
	{
	}

	genome::genome(const string& new_file) : chromosomes(),chromosomes_order(),type(natural_dna),file_name(new_file),xml_file(),species()
	{
		ifstream theFile (new_file);
		stringstream buffer;
		buffer << theFile.rdbuf();
		theFile.close();
		string file_content (buffer.str());
		vector<char> file_content_vector (file_content.begin(),file_content.end());
		file_content_vector.push_back('\0');
		xml_file.parse<0>(&file_content_vector[0]);
		rapidxml::xml_node<> * root_node;
		root_node = xml_file.first_node("life");
		rapidxml::xml_node<>* genome_node = root_node->first_node("genome");
		species = genome_node->first_attribute("species") ? genome_node->first_attribute("species")->value() : "";
		for (rapidxml::xml_node<>* chromosome_node = genome_node->first_node("chromosome"); chromosome_node; chromosome_node = chromosome_node->next_sibling())
		{
			string chromosome_name = chromosome_node->first_attribute("name")->value();
			genome_section new_chromosome(chromosome_name,this,chromosome_node);
			chromosomes[chromosome_name] = new_chromosome;
			chromosomes_order.push_back(chromosome_name);
		}
	}

	genome_section& genome::operator [](const string& i)
	{
		return chromosomes.at(i);
	}

	const genome_section& genome::operator [](const string& i) const
	{
		return chromosomes.at(i);
	}

	bool genome::is_chromosome_loaded(const string& x) const
	{
		return (chromosomes.count(x) > 0);
	}

	void genome::load_chromosome(const string& x) const
	{
		rapidxml::xml_node<>* root_node = xml_file.first_node("genome");
		if (is_chromosome_loaded(x))
		{
			return;
		}
		for (rapidxml::xml_node<>* chromosome_node = root_node->first_node("chromosome"); chromosome_node; chromosome_node = chromosome_node->next_sibling())
		{
			string chromosome_name = chromosome_node->first_attribute("name")->value();
			if (x == chromosome_name)
			{
				genome_section new_chromosome (chromosome_name,const_cast<genome*>(this),chromosome_node);
				chromosomes[chromosome_name] = new_chromosome;
				return;
			}
		}
	}

	void genome::unload_chromosome(const string& x) const
	{
		chromosomes.erase(x);
	}

	void genome::load_all_chromosomes() const
	{
		rapidxml::xml_node<>* root_node = xml_file.first_node("genome");
		for (rapidxml::xml_node<>* chromosome_node = root_node->first_node("chromosome"); chromosome_node; chromosome_node = chromosome_node->next_sibling())
		{
			string chromosome_name = chromosome_node->first_attribute("name")->value();
			if (!is_chromosome_loaded(chromosome_name))
			{
				genome_section new_chromosome (chromosome_name,const_cast<genome*>(this),chromosome_node);
				chromosomes[chromosome_name] = new_chromosome;
			}
		}
	}

	void genome::load_chromosomes(const vector<string>& new_chromosomes) const
	{
		rapidxml::xml_node<>* root_node = xml_file.first_node("genome");
		vector<string> loadable_chromosomes;
		for (const string& new_chromosome : new_chromosomes)
		{
			if (!is_chromosome_loaded(new_chromosome))
			{
				loadable_chromosomes.push_back(new_chromosome);
			}
		}
		for (rapidxml::xml_node<>* chromosome_node = root_node->first_node("chromosome"); chromosome_node; chromosome_node = chromosome_node->next_sibling())
		{
			string chromosome_name = chromosome_node->first_attribute("name")->value();
			for (const string& loadable_chromosome : loadable_chromosomes)
			{
				if (loadable_chromosome == chromosome_name)
				{
					genome_section new_chromosome (chromosome_name,const_cast<genome*>(this),chromosome_node);
					chromosomes[chromosome_name] = new_chromosome;
				}
			}
		}
	}

	void genome::unload_chromosomes(const vector<string>& x_unload) const
	{
		for (const string& x : x_unload)
		{
			unload_chromosome(x);
		}
	}

	void genome::add_chromosome(const genome_section& x)
	{
		chromosomes[x.get_name()] = x;
		chromosomes_order.push_back(x.get_name());
	}

	void genome::remove_chromosome(const string& x)
	{
		chromosomes.erase(x);
		vector<string>::iterator it_x = find(chromosomes_order.begin(),chromosomes_order.end(),x);
		chromosomes_order.erase(it_x);
	}

	void genome::switch_chromosome(const string& x,const string& y)
	{
		vector<string>::iterator it_x = find(chromosomes_order.begin(),chromosomes_order.end(),x);
		vector<string>::iterator it_y = find(chromosomes_order.begin(),chromosomes_order.end(),y);
		iter_swap(it_x,it_y);
	}

	void genome::position_chromosome(const string& x,int new_position)
	{
		vector<string>::iterator it_x = find(chromosomes_order.begin(),chromosomes_order.end(),x);
		chromosomes_order.erase(it_x);
		chromosomes_order.insert(chromosomes_order.begin() + new_position,x);
	}

	bool genome::has_gene(const string& gene_name)
	{
		for (const auto& x_chromosome : chromosomes)
		{
			if (x_chromosome.second.has_gene(gene_name))
			{
				return true;
			}
		}
		return false;
	}

	bool genome::has_gene_sequence(const string& gene_sequence)
	{
		for (const auto& x_chromosome : chromosomes)
		{
			if (x_chromosome.second.has_gene_sequence(gene_sequence))
			{
				return true;
			}
		}
		return false;
	}
}
