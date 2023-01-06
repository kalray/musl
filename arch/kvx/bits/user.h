#define ELF_NREG 70

typedef unsigned long elf_greg_t, elf_gregset_t[ELF_NREG];
typedef struct {} elf_fpregset_t;
