#ifndef __GHKEYBASE_H__
#define __GHKEYBASE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

	typedef int(__stdcall *GHKEYBASE_API_PACK)(unsigned char*, unsigned char*);
	typedef int(__stdcall *GHKEYBASE_API_GET)(unsigned char*, unsigned char*);
	typedef int(__stdcall *GHKEYBASE_API_KCV)(unsigned char*, unsigned char*);
	typedef int(__stdcall *GHKEYBASE_API_PARC)(unsigned char *, int, unsigned char *, int *);
	typedef int(__stdcall *GHKEYBASE_API_GARC)(unsigned char *, int, unsigned char *, int *);

#ifdef __cplusplus
}
#endif

class GHKeyBase
{
public:
	char DllPath[500], Message[500];

	GHKeyBase();
	~GHKeyBase();

	int Init();
	int GetKey(unsigned char *Pack, unsigned char *Key);
};






#endif //__GHKEYBASE_H__
