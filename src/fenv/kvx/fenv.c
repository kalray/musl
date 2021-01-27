#include <fenv.h>
#define KVX_SFR_CS 4
#define EMPTY_MASK 0

static inline void set_clr_cs(int setmask, int clrmask)
{
	__builtin_kvx_wfxl(KVX_SFR_CS, ((long long)setmask << 32) | clrmask);
}

int feclearexcept(int excepts)
{
	excepts &= FE_ALL_EXCEPT;
	set_clr_cs(EMPTY_MASK, excepts);
	return 0;
}

int feraiseexcept(int excepts)
{
	excepts &= FE_ALL_EXCEPT;
	set_clr_cs(excepts, EMPTY_MASK);
	return 0;
}

int fetestexcept(int excepts)
{
	fexcept_t flags;
	excepts &= FE_ALL_EXCEPT;
	flags = __builtin_kvx_get(KVX_SFR_CS);
	return (flags & excepts);
}

int fegetround(void)
{
	fenv_t rm;
	rm = __builtin_kvx_get(KVX_SFR_CS);
	return rm & FE_RND_MASK;
}

int __fesetround(int r)
{
	r &= FE_RND_MASK;
	set_clr_cs(r, FE_RND_MASK);
	return 0;
}

int fegetenv(fenv_t *envp)
{
	fenv_t fe;
	fe = __builtin_kvx_get(KVX_SFR_CS);
	*envp = (fe & (FE_ALL_EXCEPT | FE_RND_MASK));
	return 0;
}

int fesetenv(const fenv_t *envp)
{
	fenv_t fe = (envp != FE_DFL_ENV ? *envp : 0);
	fe &= (FE_ALL_EXCEPT | FE_RND_MASK);
	set_clr_cs(fe, FE_ALL_EXCEPT | FE_RND_MASK);
	return 0;
}
