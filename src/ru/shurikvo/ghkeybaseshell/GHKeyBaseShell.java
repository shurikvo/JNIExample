package ru.shurikvo.ghkeybaseshell;

public class GHKeyBaseShell {
    static
    {
        System.loadLibrary("JGHKeyBase");
    }

    native public static int PackKey(byte[] key, byte[] pack);
    native public static int GetKey(byte[] pack, byte[] Key);
    native public static int GetKCV(byte[] key, byte[] kcv);
    native public static int PackArray(byte[] cipher, int cipLen, byte[] crypt, int[] cryLen);
    native public static int GetArray(byte[] crypt, int cryLen, byte[] cipher, int[] cipLen);
}
