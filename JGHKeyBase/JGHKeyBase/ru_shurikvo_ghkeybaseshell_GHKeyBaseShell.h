/* DO NOT EDIT THIS FILE - it is machine generated */
#include "jni.h"
/* Header for class ru_shurikvo_ghkeybaseshell_GHKeyBaseShell */

#ifndef _Included_ru_shurikvo_ghkeybaseshell_GHKeyBaseShell
#define _Included_ru_shurikvo_ghkeybaseshell_GHKeyBaseShell
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     ru_shurikvo_ghkeybaseshell_GHKeyBaseShell
 * Method:    PackKey
 * Signature: ([B[B)I
 */
JNIEXPORT jint JNICALL Java_ru_shurikvo_ghkeybaseshell_GHKeyBaseShell_PackKey
  (JNIEnv *, jclass, jbyteArray, jbyteArray);

/*
 * Class:     ru_shurikvo_ghkeybaseshell_GHKeyBaseShell
 * Method:    GetKey
 * Signature: ([B[B)I
 */
JNIEXPORT jint JNICALL Java_ru_shurikvo_ghkeybaseshell_GHKeyBaseShell_GetKey
(JNIEnv *, jclass, jbyteArray, jbyteArray);

/*
 * Class:     ru_shurikvo_ghkeybaseshell_GHKeyBaseShell
 * Method:    GetKCV
 * Signature: ([B[B)I
 */

JNIEXPORT jint JNICALL Java_ru_shurikvo_ghkeybaseshell_GHKeyBaseShell_GetKCV
(JNIEnv *, jclass, jbyteArray, jbyteArray);

/*
 * Class:     ru_shurikvo_ghkeybaseshell_GHKeyBaseShell
 * Method:    PackArray
 * Signature: ([BI[B[I)I
 */
JNIEXPORT jint JNICALL Java_ru_shurikvo_ghkeybaseshell_GHKeyBaseShell_PackArray
  (JNIEnv *, jclass, jbyteArray, jint, jbyteArray, jintArray);

/*
 * Class:     ru_shurikvo_ghkeybaseshell_GHKeyBaseShell
 * Method:    GetArray
 * Signature: ([BI[B[I)I
 */
JNIEXPORT jint JNICALL Java_ru_shurikvo_ghkeybaseshell_GHKeyBaseShell_GetArray
  (JNIEnv *, jclass, jbyteArray, jint, jbyteArray, jintArray);

#ifdef __cplusplus
}
#endif
#endif
