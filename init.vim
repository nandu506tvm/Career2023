" Path to this file -> ~/.config/nvim/init.vim


set nocompatible 
filetype off

call plug#begin('~/.config/nvim/plugged')
Plug 'preservim/nerdtree'
Plug 'ctrlpvim/ctrlp.vim'
Plug 'jiangmiao/auto-pairs'
Plug 'vim-airline/vim-airline'
Plug 'vim-airline/vim-airline-themes'
Plug 'NLKNguyen/papercolor-theme'
Plug 'gruvbox-community/gruvbox'
Plug 'dracula/vim'
call plug#end()

"Hit 'ctrl+n' to open nerdtree view and 'q' to quit"
map <silent> <C-n> :NERDTreeFocus<CR>

"Hit 'ctrl+p' to open file search view and 'Esc' to close that "

" VIM editor configs"
:autocmd BufNewFile *.cpp 0r ~/.vim/templates/skeleton.cpp
filetype plugin indent on
syntax on
set noswapfile
set number
" set colorcolumn=120"
set expandtab
set tabstop=2
set shiftwidth=2
set smartindent
set noerrorbells
set fileformat=unix
set ignorecase
set termguicolors
colo papercolor
" Set themes
set background=dark
"colorscheme gruvbox

" Status Bar
set cwh=1

"Go syntax highlighting
let g:go_highlight_fields = 1
let g:go_highlight_functions = 1
let g:go_highlight_function_calls = 1
let g:go_highlight_extra_types = 1
let g:go_highlight_operators = 1

"CPP syntax highlighting
let g:cpp_class_scope_highlight = 1
let g:cpp_member_variable_highlight = 1
let g:cpp_class_decl_highlight = 1
let g:cpp_posix_standard = 1
let g:cpp_experimental_template_highlight = 1

" Auto formatting and importing
let g:go_fmt_autosave = 1
let g:go_fmt_command = "goimports"

" Status line types/signatures
let g:go_auto_type_info = 1

let g:pydocstring_formatter = 'sphinx'
" let g:airline_theme='simple'

" NerdTree
"let NERDTreeWinSize = 23
"autocmd VimEnter * NERDTree | wincmd p
" Exit Vim if NERDTree is the only window remaining in the only tab.
autocmd BufEnter * if tabpagenr('$') == 1 && winnr('$') == 1 && exists('b:NERDTree') && b:NERDTree.isTabTree() | quit | endif

" use system clipboard
set clipboard=unnamedplus

" CPP compilation/cleanup
set autowrite
autocmd filetype cpp nnoremap <C-c> :w <bar> !g++ -Wall -W -std=c++17 % -o %:r <CR>
autocmd filetype cpp nnoremap <C-k> : !rm %:r<CR>
