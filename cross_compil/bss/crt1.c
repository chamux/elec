extern long* _bss_beginning_;
extern long* _bss_end_;

int test;
long bouh;
int grr;

void fill_bss()
{
  char* dst;
  for(dst = (char *)_bss_beginning_; dst < (char *)_bss_end_; dst++)
    *dst = 0;
}
