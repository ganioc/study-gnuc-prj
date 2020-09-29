" logics
set nocompatible
set encoding=utf-8
set tabstop=2
set softtabstop=2
set shiftwidth=2
set expandtab
set smartindent
set autoindent
" wrap lines at 120 chars. 80 is somewaht antiquated with nowadays displays.
set textwidth=120
" turn syntax highlighting on
set t_Co=256
syntax on
set number
" highlight matching braces
set showmatch
" intelligent comments
set comments=sl:/*,mb:\ *,elx:\ */
set nocp
filetype plugin on		

" Install OmniCppComplete like described on http://vim.wikia.com/wiki/C++_code_completion
" " This offers intelligent C++ completion when typing ‘.’ ‘->’ or <C-o>
" " Load standard tag files
"
set tags+=~/.vim/tags/cpp

" Install DoxygenToolkit from http://www.vim.org/scripts/script.php?script_id=987
" let g:DoxygenToolkit_authorName="O3 Yang"
