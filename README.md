# data-encrypter
A tool to encrypt your files so that hackers/your jealous enemy who wants to defame you, can't access your "important files" and leak them to the world. 


## Installation 
To install, first, clone this git repository: 

```bash
$ git clone https://github.com/johnmanjohnston/data-encrypter/
```

Next, navigate to the `src/` directory:
```bash
$ cd data-encrypter/src/
```

Create a `build/` directory where the build files will be located, and navigate to it:
```bash
$ mkdir build
$ cd build
```

Next, run CMake to generate the binaries from the source, this would resemble the following:


![image](https://user-images.githubusercontent.com/97091148/217327692-84a3bc41-fa0c-4208-8128-5ccdca11f63b.png)




Now, we can run the data-encrypter binary file, and encrypt files in a directory. In this example, the directory at `../../demo/` is used
![image](https://user-images.githubusercontent.com/97091148/217315458-813b03bf-e21b-46fa-bf02-6095c03b799d.png)

We can see that the file data present in the file in the demo directory is unreadable:
![image](https://user-images.githubusercontent.com/97091148/217315614-c8717764-be8a-43f8-a1f4-4caff546375c.png)

We can decrypt the file with the same binary, but for a successful decryption we need to use the same cryption key
![image](https://user-images.githubusercontent.com/97091148/217315662-07a0c68c-3128-453b-a5c6-0e586bb51afa.png)

On using the same cryption key, we get the orginal text in our file
![image](https://user-images.githubusercontent.com/97091148/217315792-60eefd6d-7839-426b-9bf7-9387efe2a74d.png)


