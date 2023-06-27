%{
#include "command.h"
#include "lex.yy.c"

t_Command		_currentCommand;
t_SimpleCommand	*_currentSimpleCommand;

void insertArgument(char* argument) {
    if (_currentSimpleCommand->_num_av_args == 0) {
        _currentSimpleCommand->_num_av_args = 5;
        _currentSimpleCommand->_arguments = malloc(sizeof(char*) * _currentSimpleCommand->_num_av_args);
    }
    else if (_currentSimpleCommand->_num_args >= _currentSimpleCommand->_num_av_args) {
        _currentSimpleCommand->_num_av_args *= 2;
        _currentSimpleCommand->_arguments = realloc(_currentSimpleCommand->_arguments, sizeof(char*) * _currentSimpleCommand->_num_av_args);
    }

    _currentSimpleCommand->_arguments[_currentSimpleCommand->_num_args++] = strdup(argument);
}

void insertSimpleCommand(t_SimpleCommand* simpleCommand) {
    if (_currentCommand._num_av_simp_com == 0) {
        _currentCommand._num_av_simp_com = 5;
        _currentCommand._simp_com = malloc(sizeof(t_SimpleCommand*) * _currentCommand._num_av_simp_com);
    }
    else if (_currentCommand._num_simp_com >= _currentCommand._num_av_simp_com) {
        _currentCommand._num_av_simp_com *= 2;
        _currentCommand._simp_com = realloc(_currentCommand._simp_com, sizeof(t_SimpleCommand*) * _currentCommand._num_av_simp_com);
    }

    _currentCommand._simp_com[_currentCommand._num_simp_com++] = simpleCommand;
}

void clearCommand(t_Command* command) {
    for (int i = 0; i < command->_num_simp_com; i++) {
        t_SimpleCommand* simpleCommand = command->_simp_com[i];
        for (int j = 0; j < simpleCommand->_num_args; j++) {
            free(simpleCommand->_arguments[j]);
        }
        free(simpleCommand->_arguments);
        free(simpleCommand);
    }

    free(command->_simp_com);
    free(command->_out_file);
    free(command->_input_file);
    free(command->_err_file);
}

void executeCommand(t_Command* command) {
    // Implement the logic to execute the command here
    // You can use the data stored in the command structure to perform the required operations
    printf("Executing command:\n");
    printf("Number of simple commands: %d\n", command->_num_simp_com);
    printf("Out file: %s\n", command->_out_file);
    printf("Input file: %s\n", command->_input_file);
    printf("Error file: %s\n", command->_err_file);
    printf("Background: %d\n", command->_background);
    for (int i = 0; i < command->_num_simp_com; i++) {
        t_SimpleCommand* simpleCommand = command->_simp_com[i];
        printf("Simple command %d:\n", i + 1);
        printf("Number of arguments: %d\n", simpleCommand->_num_args);
        for (int j = 0; j < simpleCommand->_num_args; j++) {
            printf("Argument %d: %s\n", j + 1, simpleCommand->_arguments[j]);
        }
    }
}

void yyerror(const char* error) {
    fprintf(stderr, "Parser error: %s\n", error);
}

%}

%token GREAT
%token LESS
%token GREATGREAT
%token LESSLESS
%token PIPE
%token AND
%token WORD

%start program

%%

program : command_list
        {
            executeCommand(&_currentCommand);
            clearCommand(&_currentCommand);
        }
        ;

command_list : command
             {
                 insertSimpleCommand(_currentSimpleCommand);
                 free(_currentSimpleCommand);
                 _currentSimpleCommand = NULL;
             }
             | command_list PIPE command
             {
                 insertSimpleCommand(_currentSimpleCommand);
                 free(_currentSimpleCommand);
                 _currentSimpleCommand = NULL;
             }
             ;

command : WORD arguments redirect
        {
            struct s_SimpleCommand* simpleCommand = malloc(sizeof(struct s_SimpleCommand));
            simpleCommand->_num_av_args = 0;
            simpleCommand->_num_args = 0;
            simpleCommand->_arguments = NULL;

            insertArgument($1);

            insertSimpleCommand(simpleCommand);
        }
        ;

arguments : argument
          | arguments argument
          {
              insertArgument($2);
          }
          ;

argument : WORD
         ;

redirect : input_redirect
         | output_redirect
         | append_redirect
         ;

input_redirect : LESS WORD
               {
                   _currentCommand._input_file = strdup($2);
               }
               ;

output_redirect : GREAT WORD
                {
                    _currentCommand._out_file = strdup($2);
                }
                ;

append_redirect : GREATGREAT WORD
                {
                    _currentCommand._out_file = strdup($2);
                }
                ;

%%

int yywrap() {
    // Indicate the end of input
    return 1;
}


int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Failed to open input file\n");
        return 1;
    }

    yyin = file;

    yyparse();

    fclose(file);

    return 0;
}
