/*
写一个程序统计空格、制表符、换行符个数 
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
	//编程程序统计空格、制表符、换行书的个数 
	int blanks=0,tabs=0,newlines=0;
	int c,lastchar,done=0;
	
	while(done == 0){
		c = getchar();//getchar()从 stdin 读取下一个字符,并赋值给c 
		if(c == ' '){		/*字符常量表示一个整型值，即在ASCII字符集中的值，空格只为*/ 
			++blanks;
		}else if(c == '\t'){
			++tabs; 
		}else if(c == '\n'){
			++newlines;
		}else if(c == EOF){ /*EOF:文件结束符，是一个整型数*/ 
			if(lastchar != '\n'){
				++newlines;
			}
			done = 1;
		}
		lastchar = c;
	}

	printf("Blanks: %d\nTabs: %d\nLines: %d\n", blanks, tabs, newlines);
}

