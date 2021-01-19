import ru.shurikvo.ghkeybaseshell.GHKeyBaseShell;

import java.io.*;

public class JNIExample {
    private static int TryInt(int[] N){
        N[0] = 5;
        return N[0];
    }

    public static void main(String[] args){
        int[] N = new int[1];

        ByteMatter Byt = new ByteMatter();
        byte[] kcv = Byt.toByteArray("0000000000000000"),
                key = Byt.toByteArray("00000000000000000000000000000000"),
                pack = Byt.toByteArray("59339816BA08CCA0462E924685FC77E844EDB7CF2595F9F53A1097423BC74684E06166EFE05F748A4A54998871CBC2B7392AB802A3F868CC84CB57D434718396280B7925E17461107181218F65C52016D3276F9C1E107FD35EDBBA31D87E464CDB3DCA85F5EF1E228A02AFF6FAF706677A1C9186B63F71CEDC1B3370F9FD8972");

        GHKeyBaseShell Shell = new GHKeyBaseShell();

        System.out.println("Pack: " + Byt.toHexString(pack));
        System.out.println(" Key: " + Byt.toHexString(key));

        Shell.GetKey(pack, key);

        System.out.println("GetKey: ");
        System.out.println("Pack: " + Byt.toHexString(pack));
        System.out.println(" Key: " + Byt.toHexString(key));

        Shell.GetKCV(key, kcv);

        System.out.println("GetKCV: ");
        System.out.println(" KCV: " + Byt.toHexString(kcv));

        Shell.PackKey(key, pack);

        System.out.println("PackKey: ");
        System.out.println("Pack: " + Byt.toHexString(pack));
        System.out.println(" Key: " + Byt.toHexString(key));

        key = Byt.toByteArray("00112233445566778899AABBCCDDEEFF");
        System.out.println(" Key: " + Byt.toHexString(key));

        Shell.PackKey(key, pack);

        System.out.println("PackKey: ");
        System.out.println("Pack: " + Byt.toHexString(pack));
        System.out.println(" Key: " + Byt.toHexString(key));

        Shell.GetKey(pack, key);

        System.out.println("GetKey: ");
        System.out.println("Pack: " + Byt.toHexString(pack));
        System.out.println(" Key: " + Byt.toHexString(key));
    }
}
