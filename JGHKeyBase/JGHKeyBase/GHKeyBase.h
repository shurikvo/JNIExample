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
	int GetKCV(unsigned char *Key, unsigned char *KCV);
	int PackKey(unsigned char *Key, unsigned char *Pack);
	int PackArray(unsigned char *Cipher, int CiLen, unsigned char *Crypt, int *pCryLen);
	int GetArray(unsigned char *Crypt, int CryLen, unsigned char *Cipher, int *pCiLen);
};

#endif //__GHKEYBASE_H__
