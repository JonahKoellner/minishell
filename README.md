# minishell project

**made by** Jonah Köllner, Maximilian Reidenbach

<br>
<img width="1047" alt="Screenshot 2023-11-13 at 13 02 52" src="https://github.com/JonahKoellner/minishell/assets/33061141/ae85c0c6-24fc-4a3c-a0bb-a8d48ce0e8b4">


# Overview
### - [How to use the minishell](#how-to-use-the-minishell)
- [Building / Executing](#building--executing)
- [Usage](#Usage)

### [Example minishell Sequence](#example-minishell-sequence)


## How to use the minishell

### Building / Executing
```bash
user@pc:~/miniRT$ git clone https://github.com/JonahKoellner/minishell.git
user@pc:~/miniRT$ cd minishell
user@pc:~/miniRT$ make
...
user@pc:~/miniRT$ ./minishell
```
### Usage
``` This minishell is designed to mimic the original bash shell (there can be differences to zsh) so treat it exactly like every other Shell ```

## Example minishell Sequence
<! Needs to be simplified, prob. move this to parser section later>

```mermaid
sequenceDiagram
	box transparent Input Handeling
	participant minishell
	participant input
	end
	box transparent lexer
	participant input_to_lex
	participant get_next_token
	participant tokencount
	end
	box transparent parser
	participant parser
	participant parse_redirect
	end
	box rgb(50,0,0) Error
	participant bad_quote
	participant empty_input
	participant unexpected_token
	end
	minishell->>+input: *command
	input-->>-minishell: input
	minishell->>+input_to_lex: input
	input_to_lex->>+tokencount: input
	alt Unclosed Quotes
		tokencount-->>+input_to_lex: negative number
		input_to_lex->>+bad_quote: input
		bad_quote-->bad_quote: Prints Error Msg, adds history, frees input
		bad_quote-->>-input_to_lex: Returns -1
		input_to_lex-->>-minishell: Returns -1
	else Empty Input
		tokencount-->>+input_to_lex: 0
		input_to_lex->>+empty_input: input
		empty_input-->empty_input: frees input
		empty_input-->>-input_to_lex: 0
		input_to_lex-->>-minishell: Returns 0
	else No Error in Tokencount
		input_to_lex-->input_to_lex: allocates tokens struct
		loop For Number of tokens
			input_to_lex->>get_next_token: input
			get_next_token-->>input_to_lex: token
		end
	end
```
