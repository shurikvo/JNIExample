import ru.shurikvo.ghkeybaseshell.GHKeyBaseShell;

import java.io.*;

public class JNIExample {
    private static int TryInt(int[] N){
        N[0] = 5;
        return N[0];
    }

    public static void main(String[] args){
        int[] N = new int[1];
        byte[] key = new byte[16];

        ByteMatter Byt = new ByteMatter();

        N[0] = 10;
        System.out.println("RC: " + TryInt(N));
        System.out.println("Rz: " + N[0]);
        //System.out.println("Lb: " + System.getProperty("java.library.path"));
        //System.setProperty("java.library.path", "E:\\Java\\DLL\\JGHKeyBase\\x64\\Release");
        //System.out.println("Lb: " + System.getProperty("java.library.path"));

        byte[] pack = Byt.toByteArray("6D4F74D4734E14203923804E67A8AA0EE7402890CAA3552B1207681F802BC390E116F0DE7FAEAA0ECA8CAED6B9E2C57A65CB4DE0859BB5806B544C06DE741B8CA9B97058576357A0A15DCDA545C6D804DCEDE14B2C337A362E5B205DE1E25108FC8074AF5BE15C877B0C87E792F5EFCB0363805800C2CB44A6501C6D252FDB3B");

        GHKeyBaseShell Shell = new GHKeyBaseShell();
        //Shell.PackKey(key, pack);
        //System.out.println("Key: " + Byt.toHexString(key) + " pack: " + Byt.toHexString(pack));

        System.out.println("Pack: " + Byt.toHexString(pack));
        Shell.GetKey(pack, key);
        System.out.println("Key: " + Byt.toHexString(key) + " pack: " + Byt.toHexString(pack));
    }
}
