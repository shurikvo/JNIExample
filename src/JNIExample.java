import ru.shurikvo.ghkeybaseshell.GHKeyBaseShell;

public class JNIExample {
    public static void main(String[] args){
        ByteMatter Byt = new ByteMatter();
        byte[] kcv = Byt.toByteArray("0000000000000000"),
                key = Byt.toByteArray("00000000000000000000000000000000"),
                pack = Byt.toByteArray("59339816BA08CCA0462E924685FC77E844EDB7CF2595F9F53A1097423BC74684E06166EFE05F748A4A54998871CBC2B7392AB802A3F868CC84CB57D434718396280B7925E17461107181218F65C52016D3276F9C1E107FD35EDBBA31D87E464CDB3DCA85F5EF1E228A02AFF6FAF706677A1C9186B63F71CEDC1B3370F9FD8972");

        GHKeyBaseShell Shell = new GHKeyBaseShell();

        //-----------------------------------------------------------------------------------------
        System.out.println("-----------------------------------------------------------------------");
        System.out.println("Pack: " + Byt.toHexString(pack));
        System.out.println(" Key: " + Byt.toHexString(key));

        Shell.GetKey(pack, key);

        System.out.println("");
        System.out.println("GetKey: ");
        System.out.println("Pack: " + Byt.toHexString(pack));
        System.out.println(" Key: " + Byt.toHexString(key));
        //-----------------------------------------------------------------------------------------
        System.out.println("-----------------------------------------------------------------------");
        Shell.GetKCV(key, kcv);

        System.out.println("");
        System.out.println("GetKCV: ");
        System.out.println(" KCV: " + Byt.toHexString(kcv));
        //-----------------------------------------------------------------------------------------
        System.out.println("-----------------------------------------------------------------------");
        Shell.PackKey(key, pack);

        System.out.println("");
        System.out.println("PackKey: ");
        System.out.println("Pack: " + Byt.toHexString(pack));
        System.out.println(" Key: " + Byt.toHexString(key));
        //-----------------------------------------------------------------------------------------
        System.out.println("-----------------------------------------------------------------------");
        key = Byt.toByteArray("00112233445566778899AABBCCDDEEFF");
        System.out.println(" Key: " + Byt.toHexString(key));

        Shell.PackKey(key, pack);

        System.out.println("");
        System.out.println("PackKey: ");
        System.out.println("Pack: " + Byt.toHexString(pack));
        System.out.println(" Key: " + Byt.toHexString(key));
        //-----------------------------------------------------------------------------------------
        System.out.println("-----------------------------------------------------------------------");
        Shell.GetKey(pack, key);

        System.out.println("");
        System.out.println("GetKey: ");
        System.out.println("Pack: " + Byt.toHexString(pack));
        System.out.println(" Key: " + Byt.toHexString(key));
        //-----------------------------------------------------------------------------------------
        int Len, RC;
        int[] nLen = new int[1];
        byte[] bCrypto = new byte[150],
                bMod = Byt.toByteArray("EEA64F831E9C18A8E24B04B4192970EA5FFF4F57ED76616903C2439D9A0BDB00B0EAA0D6B147D9D43763586D4F37FD893F32337F1B4110DC439C21D89D888D5FA0772741551B478CADD22B1A8BEBBC186DFCA593D5F4116210D60C4B2BDCA0151DCEA4C39ED0419E363E320083A0A9BDF21E3565737E302EE8599C8329600A0B"),
                bExp = Byt.toByteArray("010001");

        //-----------------------------------------------------------------------------------------
        System.out.println("-----------------------------------------------------------------------");
        nLen[0] = bCrypto.length;

        System.out.println(" Exp: " + Byt.toHexString(bExp));
        System.out.println(" Len: " + bExp.length);
        System.out.println("Lans: " + nLen[0]);

        RC = Shell.PackArray(bExp, bExp.length, bCrypto, nLen);

        System.out.println("");
        System.out.println("PackArray: ");
        System.out.println(" Cry: " + Byt.toHexString(bCrypto));
        System.out.println("Lans: " + nLen[0] + " > " + RC);
        //-----------------------------------------------------------------------------------------
        System.out.println("-----------------------------------------------------------------------");
        Len = nLen[0];
        nLen[0] = bExp.length;
        bExp = Byt.toByteArray("000000");

        System.out.println(" Exp: " + Byt.toHexString(bExp));
        System.out.println(" Len: " + Len);
        System.out.println("Lans: " + nLen[0]);

        RC = Shell.GetArray(bCrypto, Len, bExp, nLen);

        System.out.println("");
        System.out.println("GetArray: ");
        System.out.println(" Exp: " + Byt.toHexString(bExp));
        System.out.println("Lans: " + nLen[0] + " > " + RC);
        //-----------------------------------------------------------------------------------------
        System.out.println("-----------------------------------------------------------------------");
        nLen[0] = bCrypto.length;

        System.out.println(" Mod: " + Byt.toHexString(bMod));
        System.out.println(" Len: " + bMod.length);
        System.out.println("Lans: " + nLen[0]);

        RC = Shell.PackArray(bMod, bMod.length, bCrypto, nLen);

        System.out.println("");
        System.out.println("PackArray: ");
        System.out.println(" Cry: " + Byt.toHexString(bCrypto));
        System.out.println("Lans: " + nLen[0] + " > " + RC);
        //-----------------------------------------------------------------------------------------
        System.out.println("-----------------------------------------------------------------------");
        Len = nLen[0];
        nLen[0] = bMod.length;
        bMod = new byte[128];

        System.out.println(" Mod: " + Byt.toHexString(bMod));
        System.out.println(" Len: " + Len);
        System.out.println("Lans: " + nLen[0]);

        RC = Shell.GetArray(bCrypto, Len, bMod, nLen);

        System.out.println("");
        System.out.println("GetArray: ");
        System.out.println(" Mod: " + Byt.toHexString(bMod));
        System.out.println("Lans: " + nLen[0] + " > " + RC);
    }
}
