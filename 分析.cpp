#include <iostream>
 void flag_encryption(unsigned char* input)
 {
 size_t len = strlen((const char*)input);
 if (len != 44)
 {
 std::cout << "length error!";
 return;
 }
 unsigned int* p = (unsigned int*)input;
 for (int i = 0; i < 11; i++)
 {
 *(p + i) = (*(p + i) * 0xccffbbbb + 0xdeadc0de) ^ 0xdeadbeef + 0xd3906;
 std::cout << ", 0x" << std::hex << *(p + i) << ' ';
 }
 std::cout << std::endl;
 // 0xb5073388 , 0xf58ea46f , 0x8cd2d760 , 0x7fc56cda , 0x52bc07da , 0x29054b48 , 
0x42d74750 , 0x11297e95 , 0x5cf2821b , 0x747970da , 0x64793c81
 }
 int main()
 {
 unsigned char a[] = "moectf{f4k3__flag__here_true_flag_in_s3cr3t}";
 flag_encryption(a);
 return 0;
 }