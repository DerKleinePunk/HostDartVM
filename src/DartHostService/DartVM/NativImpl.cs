using System;
using System.Runtime.InteropServices;

namespace DartHostService;

internal static class NativImpl
{
    [DllImport("DartVMHelper", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.Cdecl)]
    internal static extern int InitSystem(string param1);
}