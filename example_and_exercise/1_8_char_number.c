/*
дһ������ͳ�ƿո��Ʊ�������з����� 
*/ 
#include <stdio.h>

int main(void){
	/* 
  int blanks, tabs, newlines;
  int c;
  int done = 0;
  int lastchar = 0;
 
  blanks = 0;
  tabs = 0;
  newlines = 0;
 
  while(done == 0)
  {
    c = getchar();
 
    if(c == ' ')
      ++blanks;
 
    if(c == '\t')
      ++tabs;
 
    if(c == '\n')
      ++newlines;
 
    if(c == EOF)
    {
      if(lastchar != '\n')
      {
        ++newlines; 
//		 this is a bit of a semantic stretch, but it copes
//                      with implementations where a text file might not
//                      end with a newline. T

      }
      done = 1;
    }
    lastchar = c;
  }
 
	printf("Blanks: %d\nTabs: %d\nLines: %d\n", blanks, tabs, newlines);

}/* 
a as sd          d
as d f
a
asd  ^Z^Z
^Z
Blanks: 9
Tabs: 1
Lines: 4
*/ 
	//��̳���ͳ�ƿո��Ʊ����������ĸ��� 
	int blanks=0,tabs=0,newlines=0;
	int c,lastchar,done=0;
	
	while(done == 0){
		c = getchar();//getchar()�� stdin ��ȡ��һ���ַ�,����ֵ��c 
		if(c == ' '){		/*�ַ�������ʾһ������ֵ������ASCII�ַ����е�ֵ���ո�ֻΪ*/ 
			++blanks;
		}else if(c == '\t'){
			++tabs; 
		}else if(c == '\n'){
			++newlines;
		}else if(c == EOF){ /*EOF:�ļ�����������һ��������*/ 
			if(lastchar != '\n'){
				++newlines;
			}
			done = 1;
		}
		lastchar = c;
	}

	printf("Blanks: %d\nTabs: %d\nLines: %d\n", blanks, tabs, newlines);
}

