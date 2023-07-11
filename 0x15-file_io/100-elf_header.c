#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <elf.h>

#define BUF_SIZE 1024

int main(int argc, char* argv[]) {
    // Check arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
        return 98;
    }

    // Open file
    FILE *fp = fopen(argv[1], "rb");
    if (!fp) {
        fprintf(stderr, "Error: Failed to open file '%s'\n", argv[1]);
        return 98;
    }

    // Check if file is ELF
    Elf64_Ehdr header;
    if (fread(&header, sizeof(header), 1, fp) != 1) {
        fprintf(stderr, "Error: Failed to read ELF header\n");
        fclose(fp);
        return 98;
    }

    if (header.e_ident[EI_MAG0] != ELFMAG0 || header.e_ident[EI_MAG1] != ELFMAG1
        || header.e_ident[EI_MAG2] != ELFMAG2 || header.e_ident[EI_MAG3] != ELFMAG3) {
        fprintf(stderr, "Error: File '%s' is not an ELF file\n", argv[1]);
        fclose(fp);
        return 98;
    }

    // Get information from ELF header
    char buf[BUF_SIZE];
    const char* class_str;
    const char* data_str;
    const char* version_str;
    const char* osabi_str;
    const char* type_str;

    switch (header.e_ident[EI_CLASS]) {
        case ELFCLASS32:
            class_str = "ELF32";
            break;
        case ELFCLASS64:
            class_str = "ELF64";
            break;
        default:
            class_str = "Unknown";
            break;
    }

    switch (header.e_ident[EI_DATA]) {
        case ELFDATA2LSB:
            data_str = "2's complement, little endian";
            break;
        case ELFDATA2MSB:
            data_str = "2's complement, big endian";
            break;
        default:
            data_str = "Unknown";
            break;
    }

    sprintf(buf, "%d", header.e_ident[EI_VERSION]);
    version_str = buf;

    switch (header.e_ident[EI_OSABI]) {
        case ELFOSABI_SYSV:
            osabi_str = "UNIX System V ABI";
            break;
        case ELFOSABI_HPUX:
            osabi_str = "HP-UX ABI";
            break;
        case ELFOSABI_NETBSD:
            osabi_str = "NetBSD ABI";
            break;
        case ELFOSABI_LINUX:
            osabi_str = "Linux ABI";
            break;
        case ELFOSABI_SOLARIS:
            osabi_str = "Solaris ABI";
            break;
        case ELFOSABI_IRIX:
            osabi_str = "IRIX ABI";
            break;
        case ELFOSABI_FREEBSD:
            osabi_str = "FreeBSD ABI";
            break;
        case ELFOSABI_TRU64:
            osabi_str = "TRU64 UNIX ABI";
            break;
        case ELFOSABI_ARM:
            osabi_str = "ARM architecture ABI";
            break;
        case ELFOSABI_STANDALONE:
            osabi_str = "Standalone (embedded) ABI";
            break;
        default:
            osabi_str = "Unknown";
            break;
    }

    sprintf(buf, "%d", header.e_ident[EI_ABIVERSION]);
    const char* abiversion_str = buf;

    switch (header.e_type) {
        case ET_NONE:
            type_str = "NONE (No file type)";
            break;
        case ET_REL:
            type_str = "REL (Relocatable file)";
            break;
        case ET_EXEC:
            type_str = "EXEC (Executable file)";
            break;
        case ET_DYN:
            type_str = "DYN (Shared object file)";
            break;
        case ET_CORE:
            type_str = "CORE (Core file)";
            break;
        default:
            type_str = "Unknown";
            break;
    }

    sprintf(buf, "%lx", header.e_entry);
    const char* entry_str = buf;

/**
 Print information
 @
*/
    printf("ELF Header:\n");
    printf("  Magic:   %02x %02x %02x %02x\n", header.e_ident[EI_MAG0], header.e_ident[EI_MAG1], header.e_ident[EI_MAG2], header.e_ident[EI_MAG3]);
    printf("  Class:                             %s\n", class_str);
    printf("  Data:                              %s\n", data_str);
    printf("  Version:                           %s\n", version_str);
    printf("  OS/ABI:                            %s\n", osabi_str);
    printf("  ABI Version:                       %s\n", abiversion_str);
    printf("  Type:                              %s\n", type_str);
    printf("  Entry point address:               %s\n", entry_str);

    // Close file and exit
    fclose(fp);
    return 0;
}
