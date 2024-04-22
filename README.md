# scifir-biology library

scifir-biology is **under development**.

Welcome! scifir-biology is a C++ scientific library that allows to create software that work with DNA, cells, embryos, and related topics. Centrally, it's a library that provides genetic tools to create genetic software. Additional to that, it can be used to simulate cells and embryos.

The DNA files of scifir, that's, the files that follow the **DNA file format** of Scifir, use scifir-biology through **libdna**, not directly through scifir-biology.

### Team

The **Scifir Collection** is developed by [Ismael Correa Castro](https://iarfen.github.io), a software developer of 33 years old. You can email him if you find bugs, you want to request new features, or have any other need, at ismael.correa.castro@gmail.com. His ORCID is 0009-0007-3815-7053, if you want to reference this work inside any publication.

### Funding

The **Scifir Foundation** is looking for **funding**, in order to do some digital marketing and pay some other needs of the project. If you want to support this libraries, **science will thank you** for that, you can donate in this [sponsors page](https://github.com/sponsors/iarfen).

## Installation

To install scifir-biology you have to use CMake and Make. The library is called scifir-biology, and you can just link the file **libscifir-biology.a** to your project as any C++ library. The commands to install it in a Linux distribution are the following:

```
cmake .
make
make install
```

## Phylosophy of scifir-biology

scifir-biology has been constructed by thinking on supporting any kind of nomenclature and/or system used inside any branch of biology. It does not implement an specific taxonomic category excluding other classifications, it supports any kind of DNA (even imaginated ones), and any kind of species. **libdna** uses scifir-biology to handle its DNA data, but scifir-biology can be used for any other files that store DNA, and for any database of genomes, not only for DNA files of Scifir. Because of that reason, all genes_collection classes are interfaces or abstract classes, and allow then to implement the access of any kind of data system.

## Storing scifir-biology data

The data of the entities of scifir-biology should always be stored in the following way:

- **genes:** Store it as text data using the gene format of scifir.
- **species:** Store it as text data using the **binomial nomenclature** of species, or, if there isn't a possible binomial nomenclature, use parenthesis specifying the format you're using.

## Loading data through interfaces

scifir-biology can be used to load biological data of any kinf of source, being files, databases, or cloud services. To do that it's needed to implement the interfaces that load this data, all of those have the suffix **_source**. For example, to load genetic data from AWS you have to create implementations of gene_info_collection_source, genes_collection_source and genome_source by adding inside them the functions of AWS that you need to get that data from it.

This programming paradigm of loading data through interfaces and allowing then a very flexible handling of data is a new design pattern, invented here inside scifir-biology, called **flexible data loading**. This design pattern has been invented by the author of this library, Ismael Correa.

## Core features

### Genes

All classes of genes have the base class gene. The two classes of genes that inherit from the gene base class are earth_gene and extended_gene. They have the following characteristics:

- **earth_gene:** Class that allows to work with the common nitrogenous bases: T, C, G, A and U.
- **extended_gene:** Class that allows to work with any artificial or extraterrestrial nitrogenous base, by defining it as a new nitrogenous base.
