#include "stdafx.h"
#include "ru_shurikvo_ghkeybaseshell_GHKeyBaseShell.h"
#include "GHKeyBase.h"

JNIEXPORT jint JNICALL Java_ru_shurikvo_ghkeybaseshell_GHKeyBaseShell_PackKey(JNIEnv *env, jclass myclass, jbyteArray key, jbyteArray pack)
{

	jbyte *pKey = env->GetByteArrayElements(key, false);
	jbyte *pPack = env->GetByteArrayElements(pack, false);

	*(pPack + 0) = 0x00;
	*(pPack + 1) = 0x01;
	*(pPack + 2) = 0x02;
	*(pPack + 3) = 0x03;
	*(pPack + 4) = 0x04;
	*(pPack + 5) = 0x05;
	*(pPack + 6) = 0x06;
	*(pPack + 7) = 0x07;
	*(pPack + 8) = 0x08;
	*(pPack + 9) = 0x09;
	*(pPack + 10) = 0x0A;
	*(pPack + 11) = 0x0B;
	*(pPack + 12) = 0x0C;
	*(pPack + 13) = 0x0D;
	*(pPack + 14) = 0x0E;
	*(pPack + 15) = 0x0F;

	env->ReleaseByteArrayElements(key, pKey, JNI_COMMIT);
	env->ReleaseByteArrayElements(pack, pPack, JNI_COMMIT);

	return 16;
}

JNIEXPORT jint JNICALL Java_ru_shurikvo_ghkeybaseshell_GHKeyBaseShell_GetKey(JNIEnv *env, jclass myclass, jbyteArray pack, jbyteArray key)
{
	int RC;
	jbyte *pPack = env->GetByteArrayElements(pack, false);
	jbyte *pKey = env->GetByteArrayElements(key, false);
	GHKeyBase Bky;

	RC = Bky.Init();
	if (RC >= 0)
		RC = Bky.GetKey((unsigned char *)pPack, (unsigned char *)pKey);

	/**(pKey + 0) = 0x40;
	*(pKey + 1) = 0x41;
	*(pKey + 2) = 0x42;
	*(pKey + 3) = 0x43;
	*(pKey + 4) = 0x44;
	*(pKey + 5) = 0x45;
	*(pKey + 6) = 0x46;
	*(pKey + 7) = 0x47;
	*(pKey + 8) = 0x48;
	*(pKey + 9) = 0x49;
	*(pKey + 10) = 0x4A;
	*(pKey + 11) = 0x4B;
	*(pKey + 12) = 0x4C;
	*(pKey + 13) = 0x4D;
	*(pKey + 14) = 0x4E;
	*(pKey + 15) = 0x4F;*/

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

JNIEXPORT jint JNICALL Java_ru_shurikvo_ghkeybaseshell_GHKeyBaseShell_PackArray(JNIEnv *env, jclass myclass, jbyteArray cipher, jint cipLen, jbyteArray crypto, jintArray cryLen)
{
	return 0;
}

JNIEXPORT jint JNICALL Java_ru_shurikvo_ghkeybaseshell_GHKeyBaseShell_GetArray(JNIEnv *env, jclass myclass, jbyteArray crypto, jint cryLen, jbyteArray cipher, jintArray cipLen)
{
	return 0;
}




