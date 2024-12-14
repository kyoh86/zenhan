# zenhan

A command-line tool to switch the IME (Input Method Editor) mode on Windows. Similar to [im-select](https://github.com/daipeihust/im-select).

Forked from [kaz399/spzenhan.vim](https://github.com/kaz399/spzenhan.vim).

## Features

- Turn on/off the IME mode programmatically from the terminal.
- Check the current IME mode status.

## Usage

To turn on IME:

```console
zenhan.exe 1
```

To turn off IME:

```console
zenhan.exe 0
```

To get the current IME status:

```console
zenhan.exe
echo $?
```

The exit code (0 or 1) indicates IME off or on status, respectively.

## Build

If you want to build from source, you can use clang++ on Windows:

```console
clang++ -std=c++11 -O2 -mwindows main.cc -o zenhan.exe -limm32 -luser32 -lmsvcrt -fuse-ld=lld-link
```

You will need [LLVM](https://llvm.org/) installed. Or you can use Visual Studio and its build tools.  
The tool has been tested on Windows 10/11.

## License

This project is distributed under the [Unlicense](./LICENSE), as per the original repository.
