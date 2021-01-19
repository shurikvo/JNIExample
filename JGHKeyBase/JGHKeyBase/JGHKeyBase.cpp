#include "stdafx.h"
#include "ru_shurikvo_ghkeybaseshell_GHKeyBaseShell.h"
#include "GHKeyBase.h"

JNIEXPORT jint JNICALL Java_ru_shurikvo_ghkeybaseshell_GHKeyBaseShell_PackKey(JNIEnv *env, jclass myclass, jbyteArray key, jbyteArray pack)
{
	int RC = 0;
	jbyte *pKey = env->GetByteArrayElements(key, false);
	jbyte *pPack = env->GetByteArrayElements(pack, false);

	RC = Bky.PackKey((unsigned char *)pKey, (unsigned char *)pPack);

	printf("PackKey: RC = %d\n", RC);
	if (RC < 0)
	{
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

	printf("GetKey: RC = %d\n", RC);
	if (RC < 0)
	{
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

	printf("GetKCV: RC = %d\n", RC);
	if (RC < 0)
	{
		env->ReleaseByteArrayElements(kcv, pKCV, JNI_ABORT);
		printf("GetKCV: %s\n", Bky.Message);
	}
	else
		env->ReleaseByteArrayElements(kcv, pKCV, JNI_COMMIT);
	env->ReleaseByteArrayElements(key, pKey, JNI_ABORT);

	return RC;
}

JNIEXPORT jint JNICALL Java_ru_shurikvo_ghkeybaseshell_GHKeyBaseShell_PackArray(JNIEnv *env, jclass myclass, jbyteArray cipher, jint cipLen, jbyteArray crypto, jintArray cryLen)
{
	return 0;
}

JNIEXPORT jint JNICALL Java_ru_shurikvo_ghkeybaseshell_GHKeyBaseShell_GetArray(JNIEnv *env, jclass myclass, jbyteArray crypto, jint cryLen, jbyteArray cipher, jintArray cipLen)
{
	return 0;
}




