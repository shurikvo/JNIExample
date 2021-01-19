# JNIExample
An attempt to use JNI

Tere is a GHKeyBase_64.dll dynamic library. Its purpose is encrypt/decrypt keys to/from open source.

GHKeyBase_64.dll is used in many C++ and C# projects. Now I want to use it in Java projects too.

At first i created ru.shurikvo.ghkeybaseshell.GHKeyBaseShell class and then make ru_shurikvo_ghkeybaseshell_GHKeyBaseShell.h (see jnl.bat).

Next I create C++ DLL project (MSVS 2017) (see JGHKeyBase). The result is JGHKeyBase.dll.

JGHKeyBase.dll loads GHKeyBase_64.dll and calls its functions.

So it all works properly. Have to keep in mind all components must be x64. It forced me rewrite GHKeyBase_64.dll (initial was GHKeyBase.dll).
