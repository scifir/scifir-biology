# scifir-biology

Welcome! scifir-biology is a C++ scientific library that allows to create software that work with DNA, cells, embryos, and related topics. Centrally, it's a library that provides genetic tools to create genetic software. Additional to that, it can be used to simulate cells and embryos.

## Core features

### Genes

All classes of genes have the base class gene. The two classes of genes that inherit from the gene base class are earth_gene and extended_gene. They have the following characteristics:

- **earth_gene:** Class that allows to work with the common nitrogenous bases: T, C, G, A and U.
- **extended_gene:** Class that allows to work with any artificial or extraterrestrial nitrogenous base, by defining it as a new nitrogenous base.
