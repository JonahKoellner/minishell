%{
#include "command.h"
#include "y.tab.h"
%}

%%
[ \n]				{}
">"					{return GREAT;}
"<"					{return LESS;}
">>"				{return GREATGREAT;}
"<<"				{return LESSLESS;}
"|"					{return PIPE;}
"&"					{return AND;}
[^ \t\n][^ \t\n]*	{return WORD;}

%%
