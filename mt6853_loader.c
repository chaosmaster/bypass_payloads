int main() {

    int (*usbdl_get_data)() = (void*)0xe9b9;
    int (*usbdl_put_dword)() = (void*)0xe977;
    void (**ptr_send)() = (void*)0x10288c;
    *ptr_send = (void *)0x4245;

    usbdl_put_dword(0xD1D2D3D4);

    int size;
    int (*address)();

    usbdl_get_data(&address, 4);
    usbdl_get_data(&size, 4);

    usbdl_get_data(address, size);

    address();

}
