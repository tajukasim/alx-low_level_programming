#include <stdio.h>
#include <stdlib.h>
#include <elf.h>

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <ELF file>\n", argv[0]);
        return 1;
    }

    FILE* fp = fopen(argv[1], "rb");
    if (!fp) {
        printf("Error: Failed to open file '%s'\n", argv[1]);
        return 1;
    }

    Elf64_Ehdr header;
    fread(&header, sizeof(header), 1, fp);

    printf("ELF header:\n");
    printf("  Magic number: ");
    for (int i = 0; i < EI_NIDENT; i++) {
        printf("%02x ", header.e_ident[i]);
    }
    printf("\n");

    printf("  Class:       %d-bit\n", header.e_ident[EI_CLASS] == ELFCLASS32 ? 32 : 64);
    printf("  Data:        %s\n", header.e_ident[EI_DATA] == ELFDATA2LSB ? "little-endian" : "big-endian");
    printf("  Version:     %d\n", header.e_ident[EI_VERSION]);
    printf("  OS/ABI:      %d\n", header.e_ident[EI_OSABI]);
    printf("  ABI version: %d\n", header.e_ident[EI_ABIVERSION]);
    printf("  Type:        %d\n", header.e_type);
    printf("  Machine:     %d\n", header.e_machine);
    printf("  Version:     %d\n", header.e_version);
    printf("  Entry point: 0x%lx\n", header.e_entry);
    printf("  Program header table offset: %lu\n", header.e_phoff);
    printf("  Section header table offset: %lu\n", header.e_shoff);
    printf("  Flags:       0x%x\n", header.e_flags);
    printf("  Header size: %d bytes\n", header.e_ehsize);
    printf("  Program header size: %d bytes\n", header.e_phentsize);
    printf("  Program header count: %d\n", header.e_phnum);
    printf("  Section header size: %d bytes\n", header.e_shentsize);
    printf("  Section header count: %d\n", header.e_shnum);
    printf("  Section header string table index: %d\n", header.e_shstrndx);

    fclose(fp);
    return 0;
}
