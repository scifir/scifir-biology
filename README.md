# scifir-biology library

scifir-biology is **under development**.

Welcome! scifir-biology is a C++ scientific library that allows to create software that work with DNA, cells, embryos, and related topics. Centrally, it's a library that provides genetic tools to create genetic software. Additional to that, it can be used to simulate cells and embryos.

The DNA files of scifir, that's, the files that follow the **DNA file format** of Scifir, use scifir-biology through **libdna**, not directly through scifir-biology.

## Phylosophy of scifir-biology

scifir-biology has been constructed by thinking on supporting any kind of nomenclature and/or system used inside any branch of biology. It does not implement an specific taxonomic category excluding other classifications, it supports any kind of DNA (even imaginated ones), and any kind of species. **libdna** uses scifir-biology to handle its DNA data, but scifir-biology can be used for any other files that store DNA, and for any database of genomes, not only for DNA files of Scifir. Because of that reason, all genes_collection classes are interfaces or abstract classes, and allow then to implement the access of any kind of data system.

## Core features

### Genes

All classes of genes have the base class gene. The two classes of genes that inherit from the gene base class are earth_gene and extended_gene. They have the following characteristics:

- **earth_gene:** Class that allows to work with the common nitrogenous bases: T, C, G, A and U.
- **extended_gene:** Class that allows to work with any artificial or extraterrestrial nitrogenous base, by defining it as a new nitrogenous base.
