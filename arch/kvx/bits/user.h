#define ELF_NREG 64

struct user_regs_struct
{
  /* GPR */
  unsigned long long gpr_regs[ELF_NREG];

  /* SFR */
  unsigned long lc; 
  unsigned long le; 
  unsigned long ls; 
  unsigned long ra; 

  unsigned long cs; 
  unsigned long spc;
};

typedef unsigned long elf_greg_t, elf_gregset_t[ELF_NREG];
typedef struct {} elf_fpregset_t;
