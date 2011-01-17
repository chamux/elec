extern char _bss_beginning_;
extern char _bss_end_;

void fill_bss()
{
  char* dst;
  for(dst = (char *)(& _bss_beginning_); dst < (char *)(& _bss_end_); dst++)
    *dst = 0;
}
