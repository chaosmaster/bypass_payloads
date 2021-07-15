int main() {

    int (*usbdl_get_data)() = (void*)0xBE4B;
    int (*usbdl_put_dword)() = (void*)0xBE09;
    void (**ptr_send)() = (void*)0x103088;
    *ptr_send = (void *)0x4439;

    usbdl_put_dword(0xD1D2D3D4);

    int size;
    int (*address)();

    usbdl_get_data(&address, 4);
    usbdl_get_data(&size, 4);

    usbdl_get_data(address, size);

    address();

}
