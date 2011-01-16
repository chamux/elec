extern char _bss_beginning_;
extern char _bss_end_;

extern char _data_beginning_flash_;
extern char _data_beginning_ram_;
extern char _data_end_ram_;

int test;
long bouh;
int grr;

void fill_bss()
{
  char* dst;
  for(dst = (char *)(& _bss_beginning_); dst < (char *)(& _bss_end_); dst++)
    *dst = 0;
}

void copy_data_ram()
{
  char * src = (char *)(& _data_beginning_flash_);
  char * dst = (char *)(& _data_beginning_ram_);

  while(dst < (char *)(& _data_end_ram_))
  {
    *dst++ = *src++; 
  }

}
