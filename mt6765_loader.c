int main() {

    int (*usbdl_get_data)() = (void*)0xBD15;
    int (*usbdl_put_dword)() = (void*)0xBCD3;
    void (**ptr_send)() = (void*)0x10286C;
    *ptr_send = (void *)0x1FA9;

    usbdl_put_dword(0xD1D2D3D4);

    int size;
    int (*address)();

    usbdl_get_data(&address, 4);
    usbdl_get_data(&size, 4);

    usbdl_get_data(address, size);

    address();

}
