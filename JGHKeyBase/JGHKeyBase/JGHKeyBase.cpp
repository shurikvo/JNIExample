#include "stdafx.h"
#include "ru_shurikvo_ghkeybaseshell_GHKeyBaseShell.h"
#include "GHKeyBase.h"

JNIEXPORT jint JNICALL Java_ru_shurikvo_ghkeybaseshell_GHKeyBaseShell_PackKey(JNIEnv *env, jclass myclass, jbyteArray key, jbyteArray pack)
{
	int RC = 0;
	jbyte *pKey = env->GetByteArrayElements(key, false);
	jbyte *pPack = env->GetByteArrayElements(pack, false);

	RC = Bky.PackKey((unsigned char *)pKey, (unsigned char *)pPack);

	if (RC < 0)
	{
		printf("PackKey: RC = %d\n", RC);
		env->ReleaseByteArrayElements(pack, pPack, JNI_ABORT);
		printf("PackKey: %s\n", Bky.Message);
	}
	else
		env->ReleaseByteArrayElements(pack, pPack, JNI_COMMIT);
	env->ReleaseByteArrayElements(key, pKey, JNI_ABORT);

	return RC;
}

JNIEXPORT jint JNICALL Java_ru_shurikvo_ghkeybaseshell_GHKeyBaseShell_GetKey(JNIEnv *env, jclass myclass, jbyteArray pack, jbyteArray key)
{
	int RC = 0;
	jbyte *pPack = env->GetByteArrayElements(pack, false);
	jbyte *pKey = env->GetByteArrayElements(key, false);

	RC = Bky.GetKey((unsigned char *)pPack, (unsigned char *)pKey);

	if (RC < 0)
	{
		printf("GetKey: RC = %d\n", RC);
		env->ReleaseByteArrayElements(key, pKey, JNI_ABORT);
		printf("GetKey: %s\n", Bky.Message);
	}
	else
		env->ReleaseByteArrayElements(key, pKey, JNI_COMMIT);
	env->ReleaseByteArrayElements(pack, pPack, JNI_ABORT);

	return RC;
}

JNIEXPORT jint JNICALL Java_ru_shurikvo_ghkeybaseshell_GHKeyBaseShell_GetKCV(JNIEnv *env, jclass myclass, jbyteArray key, jbyteArray kcv)
{
	int RC = 0;
	jbyte *pKey = env->GetByteArrayElements(key, false);
	jbyte *pKCV = env->GetByteArrayElements(kcv, false);

	RC = Bky.GetKCV((unsigned char *)pKey, (unsigned char *)pKCV);

	if (RC < 0)
	{
		printf("GetKCV: RC = %d\n", RC);
		env->ReleaseByteArrayElements(kcv, pKCV, JNI_ABORT);
		printf("GetKCV: %s\n", Bky.Message);
	}
	else
		env->ReleaseByteArrayElements(kcv, pKCV, JNI_COMMIT);
	env->ReleaseByteArrayElements(key, pKey, JNI_ABORT);

	return RC;
}

JNIEXPORT jint JNICALL Java_ru_shurikvo_ghkeybaseshell_GHKeyBaseShell_PackArray(JNIEnv *env, jclass myclass, 
	jbyteArray cipher, jint cipLen, jbyteArray crypto, jintArray cryLen)
{
	int RC = 0;
	jbyte *pCipher = env->GetByteArrayElements(cipher, false);
	jbyte *pCrypto = env->GetByteArrayElements(crypto, false);
	jint *pCryLen = env->GetIntArrayElements(cryLen, false);

	RC = Bky.PackArray((unsigned char *)pCipher, (int)cipLen, (unsigned char *)pCrypto, (int *)pCryLen);

	if (RC < 0)
	{
		printf("PackArray: RC = %d\n", RC);
		env->ReleaseByteArrayElements(crypto, pCrypto, JNI_ABORT);
		env->ReleaseIntArrayElements(cryLen, pCryLen, JNI_ABORT);
		printf("PackArray: %s\n", Bky.Message);
	}
	else
	{
		env->ReleaseByteArrayElements(crypto, pCrypto, JNI_COMMIT);
		env->ReleaseIntArrayElements(cryLen, pCryLen, JNI_COMMIT);
	}
	env->ReleaseByteArrayElements(cipher, pCipher, JNI_ABORT);

	return RC;
}

JNIEXPORT jint JNICALL Java_ru_shurikvo_ghkeybaseshell_GHKeyBaseShell_GetArray(JNIEnv *env, jclass myclass, 
	jbyteArray crypto, jint cryLen, jbyteArray cipher, jintArray cipLen)
{
	int RC = 0;
	jbyte *pCrypto = env->GetByteArrayElements(crypto, false);
	jbyte *pCipher = env->GetByteArrayElements(cipher, false);
	jint *pCipLen = env->GetIntArrayElements(cipLen, false);

	RC = Bky.GetArray((unsigned char *)pCrypto, (int)cryLen, (unsigned char *)pCipher, (int *)pCipLen);

	if (RC < 0)
	{
		printf("GetArray: RC = %d\n", RC);
		env->ReleaseByteArrayElements(cipher, pCipher, JNI_ABORT);
		env->ReleaseIntArrayElements(cipLen, pCipLen, JNI_ABORT);
		printf("GetArray: %s\n", Bky.Message);
	}
	else
	{
		env->ReleaseByteArrayElements(cipher, pCipher, JNI_COMMIT);
		env->ReleaseIntArrayElements(cipLen, pCipLen, JNI_COMMIT);
	}
	env->ReleaseByteArrayElements(crypto, pCrypto, JNI_ABORT);

	return RC;
}




