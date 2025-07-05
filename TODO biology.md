# TODO - scifir-biology

## CURRENT (2)

- TODO: add lazy initialization to the genome class of chromosomes and to the chromosome class to genes
- TODO: (maybe) add a full_common_gene class for genes that have only normal bases (not ultimate bases) which use string as container. Do it only if the loading of a gene is expensive
- TODO: collections should have the data_sources in a map, with a name for each source

## DNA (14)

- TODO: add a text output different for all classes protein(sequence),gene(sequence),etc
- TODO: finish the gene_collection class
- TODO: add gene::is_valid(),chromosome::is_valid(),dna::is_valid()
- TODO: gene fingerprint, chromosomes fingerprint, dna fingerprint

- TODO: find out how to use mutable properly
- TODO: make load_gene and load_genes() work with const

- TODO: add a shared_ptr\<vector\<nbase\>\> to the gene class in order to access quickly the nitrogenous bases

- TODO: warn if the DNA is composed by an non-divisible per 3 number of nitrogenous bases
- TODO: save() function to store .dna files. new_genes should be stored as another member-variable in order to optimize how to save the file without asking to new_genes all the time
- TODO: maybe the dna should load with a buffer and with multi-threading
- TODO: add the two dna strings (of the dna molecule, the male and the female), and add H- or M- to the operator[] of the dna class as a prefix to select the chain
- TODO: see which enumeration systems exists for gene names and use one inside dna class

- TODO: convert DNA to RNA and viceversa
- TODO: function that detects the sequence that directs the mrna to some place inside the cell

## DNA (1)

- TODO: it should detect all genes inside a sequence, and give a vector of them

## CUSTOM_GENE (1)

- TODO: create a system for specifying new codons for custom nitrogenous bases

## CELLS (1)

- TODO: create the cell class

## EMBRYOS (1)

- TODO: create the embryo class

## TAXONOMY (1)

- TODO: create a good constructor for taxonomic_category that allows to initialize all categories easy

## GENETICS FILES (4)

- TODO: .genoma files
- TODO: .dna files can be full or can be compressed (by saying only their respective gen number, without the sequence)
- TODO: .mcd (mythical creature dna) file (it goes inside another program, not this library)
- TODO: compression algorithm maybe using zlib for dna files

## C++ (4)

- TODO: check if to store rapidxml nodes as pointers consumes a lot or a few of memory (if it consumes a lot it's needed to change the xml library being used)
- TODO: dna.cpp: see which is the best method to travel rapidxml, if to use file<> of rapidxml or if to use the actual fstream (maybe other files too)
- TODO: see if it's possible to support to write numbers with chars
- TODO: if the pointers of rapidxml have to be deleted or not

## ANIMAL AND VEGETABLE (1)

- TODO: .life_sample files

## ADVANCED (2)

- TODO: fingerprint of dna files to avoid creation of false files
- TODO: test if virtual operator[] of gene class reduces performance related to another mecanism
