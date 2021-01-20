#include "stdafx.h"

	HINSTANCE hDllGHKB = NULL;
	GHKEYBASE_API_GET	hGetKey = NULL;
	GHKEYBASE_API_PACK	hPackKey = NULL;
	GHKEYBASE_API_KCV	hGetKCV = NULL;
	GHKEYBASE_API_PARC	hPackArc = NULL;
	GHKEYBASE_API_GARC	hGetArc = NULL;

	int GHKeyBase::GetKey(unsigned char *bCrypto, unsigned char *bKey)
	{
		int RC;

		RC = (hGetKey)(bCrypto, bKey);

		return RC;
	}

	int GHKeyBase::GetKCV(unsigned char *bKey, unsigned char *bKCV)
	{
		int RC;

		RC = (hGetKCV)(bKey, bKCV);

		return RC;
	}

	int GHKeyBase::PackKey(unsigned char *bKey, unsigned char *bCrypto)
	{
		int RC;

		RC = (hPackKey)(bKey, bCrypto);

		return RC;
	}

	int GHKeyBase::PackArray(unsigned char *Cipher, int CiLen, unsigned char *Crypt, int *pCryLen)
	{
		int RC;

		RC = (hPackArc)(Cipher, CiLen, Crypt, pCryLen);

		return RC;
	}

	int GHKeyBase::GetArray(unsigned char *Crypt, int CryLen, unsigned char *Cipher, int *pCiLen)
	{
		int RC;

		RC = (hGetArc)(Crypt, CryLen, Cipher, pCiLen);

		return RC;
	}

int GHKeyBase::Init()
{
	//int RC;
	char sFunc[100];
	wchar_t wtext[500];

	mbstowcs(wtext, DllPath, strlen(DllPath) + 1);
	hDllGHKB = LoadLibrary(wtext);
	if(hDllGHKB == NULL)
	{
		sprintf_s(Message,"Cannot load library  %s",DllPath);
		return -1;
	}

	sprintf_s(sFunc, "GetKey");
	hGetKey = (GHKEYBASE_API_GET)GetProcAddress(hDllGHKB, sFunc);
	if (hGetKey == NULL)
	{
		sprintf_s(Message, "Cannot get proc addres %s", sFunc);
		FreeLibrary(hDllGHKB);
		hDllGHKB = NULL;
		return -2;
	}

	sprintf_s(sFunc, "GetKCV");
	hGetKCV = (GHKEYBASE_API_KCV)GetProcAddress(hDllGHKB, sFunc);
	if (hGetKCV == NULL)
	{
		sprintf_s(Message, "Cannot get proc addres %s", sFunc);
		FreeLibrary(hDllGHKB);
		hDllGHKB = NULL;
		return -2;
	}

	sprintf_s(sFunc, "PackKey");
	hPackKey = (GHKEYBASE_API_PACK)GetProcAddress(hDllGHKB, sFunc);
	if (hPackKey == NULL)
	{
		sprintf_s(Message, "Cannot get proc addres %s", sFunc);
		FreeLibrary(hDllGHKB);
		hDllGHKB = NULL;
		return -2;
	}

	sprintf_s(sFunc, "PackArray");
	hPackArc = (GHKEYBASE_API_PARC)GetProcAddress(hDllGHKB, sFunc);
	if (hPackArc == NULL)
	{
		sprintf_s(Message, "Cannot get proc addres %s", sFunc);
		FreeLibrary(hDllGHKB);
		hDllGHKB = NULL;
		return -2;
	}

	sprintf_s(sFunc, "GetArray");
	hGetArc = (GHKEYBASE_API_GARC)GetProcAddress(hDllGHKB, sFunc);
	if (hGetArc == NULL)
	{
		sprintf_s(Message, "Cannot get proc addres %s", sFunc);
		FreeLibrary(hDllGHKB);
		hDllGHKB = NULL;
		return -2;
	}

	return 0;
}

GHKeyBase::GHKeyBase()
{
	//sprintf_s(DllPath, "C:\\Rosan\\Handlers\\GHKeyBase.dll");
	sprintf_s(DllPath, "GHKeyBase_64.dll");
	sprintf_s(Message,"");
}

GHKeyBase::~GHKeyBase()
{
}
