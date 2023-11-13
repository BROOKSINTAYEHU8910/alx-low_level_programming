#include "main.h"


/**
 * main - The entry point for the ELF header program
 * @argc: The number of arguments passed to the program
 * @argv: An array of pointer to the arguments
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
int fp;
Elf64_Ehdr *ptr;
ssize_t read_file;
if (argc != 2)
{dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
return (98);
}
fp = open(argv[1], O_RDONLY);
if (fp == -1)
{dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
return (98);
}
ptr = malloc(sizeof(Elf64_Ehdr));
if (ptr == NULL)
{
close_elf(fp);
dprintf(STDERR_FILENO, "Error: Can't allocate memory\n");
return (98);
}
read_file = read(fp, ptr, sizeof(Elf64_Ehdr));
if (read_file == -1)
{free(ptr);
close_elf(fp);
dprintf(STDERR_FILENO, "Error: Couldn't read file %s\n", argv[1]);
return (98);
}
check_elf(ptr->e_ident);
printf("ELF Header:\n");
print_magic(ptr->e_ident);
print_class(ptr->e_ident);
print_data(ptr->e_ident);
print_version(ptr->e_ident);
print_osabi(ptr->e_ident);
print_abi(ptr->e_ident);
print_type(ptr->e_type, ptr->e_ident);
print_entry_point(ptr->e_entry, ptr->e_ident);
free(ptr);
close_elf(fp);
return (0);
}

/**
 * check_elf - A function that checks if the file is in ELF format
 * @e_ident: A Pointer to an array of ELF versions
 * Return: void
 */
void check_elf(unsigned char *e_ident)
{
int j;
for (j = 0; j < 4; j++)
{
if (e_ident[j] != 127 &&
e_ident[j] != 'E' &&
e_ident[j] != 'L' &&
e_ident[j] != 'F')
{
dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
exit(98);
}
}
}

/**
 * print_magic - A function that prints the ELF magic num
 * @e_ident: A pointer to an array of ELF versions
 * Return: Nothing
 */

void print_magic(unsigned char *e_ident)
{
int j;
printf("  Magic:   ");
for (j = 0; j < EI_NIDENT; j++)
{
printf("%02x", e_ident[j]);
if (j == EI_NIDENT - 1)
printf("\n");
else
printf(" ");
}
}
/**
 * print_class - A function that prints the ELF class
 * @e_ident: A pointer to an array of ELF versions
 * Return: Nothing
 */

void print_class(unsigned char *e_ident)
{
printf("  Class:                             ");
switch (e_ident[EI_CLASS])
{
case ELFCLASSNONE:
printf("none\n");
break;
case ELFCLASS32:
printf("ELF32\n");
break;
case ELFCLASS64:
printf("ELF64\n");
break;
default:
printf("<unknown: %x>\n", e_ident[EI_CLASS]);
}
}

/**
 * print_data - A funtion that prits the ELF data formats
 * @e_ident: A pointer to an array of ELF versions
 * Return: Void
 */

void print_data(unsigned char *e_ident)
{
printf("  Data:                              ");
switch (e_ident[EI_DATA])
{
case ELFDATANONE:
printf("none\n");
break;
case ELFDATA2LSB:
printf("2's complement, little endian\n");
break;
case ELFDATA2MSB:
printf("2's complement, big endian\n");
break;
default:
printf("<unknown: %x>\n", e_ident[EI_CLASS]);
}
}

/**
 * print_version -A function that prints the ELF version
 * @e_ident: A pointer to an array of ELF version
 */

void print_version(unsigned char *e_ident)
{
printf("  Version:                           %d", e_ident[EI_VERSION]);
switch (e_ident[EI_VERSION])
{
case EV_CURRENT:
printf(" (current)\n");
break;
default:
printf("\n");
break;
}
}

/**
 * print_abi - A funtion that prints the ABI version
 * @e_ident:  A pointer to an array of Elf versions
 * Return:  Nothing
 */

void print_abi(unsigned char *e_ident)
{
printf("  ABI Version:                       %d\n", e_ident[EI_ABIVERSION]);
}

/**
 * print_osabi - A funtion that prints the OS/ABI info
 * @e_ident: A pointer to an array of ELF versions
 * Return: Nothing
 */

void print_osabi(unsigned char *e_ident)
{
printf("  OS/ABI:                            ");
switch (e_ident[EI_OSABI])
{
case ELFOSABI_NONE:
printf("UNIX - System V\n");
break;
case ELFOSABI_HPUX:
printf("UNIX - HP-UX\n");
break;
case ELFOSABI_NETBSD:
printf("UNIX - NetBSD\n");
break;
case ELFOSABI_LINUX:
printf("UNIX - Linux\n");
break;
case ELFOSABI_SOLARIS:
printf("UNIX - Solaris\n");
break;
case ELFOSABI_IRIX:
printf("UNIX - IRIX\n");
break;
case ELFOSABI_FREEBSD:
printf("UNIX - FreeBSD\n");
break;
case ELFOSABI_TRU64:
printf("UNIX - TRU64\n");
break;
case ELFOSABI_ARM:
printf("ARM\n");
break;
case ELFOSABI_STANDALONE:
printf("Standalone App\n");
break;
default:
printf("<unknown: %x>\n", e_ident[EI_OSABI]);
}
}

/**
 * print_type - A function that prints the ELF type
 * @e_type: The ELF type for printing
 * @e_ident: A pointer to an array of ELF versions
 */

void print_type(unsigned int e_type, unsigned char *e_ident)
{
if (e_ident[EI_DATA] == ELFDATA2MSB)
e_type >>= 8;
printf("  Type:                              ");
switch (e_type)
{
case ET_NONE:
printf("NONE (None)\n");
break;
case ET_REL:
printf("REL (Relocatable file)\n");
break;
case ET_EXEC:
printf("EXEC (Executable file)\n");
break;
case ET_DYN:
printf("DYN (Shared object file)\n");
break;
case ET_CORE:
printf("CORE (Core file)\n");
break;
default:
printf("<unknown: %x>\n", e_type);
}
}

/**
 * print_entry_point - A function that prints the ELF entry point address
 * @e_entry: The entry poit address to be printed
 * @e_ident: A pointer to an array of ELF versions
 */

void print_entry_point(unsigned long int e_entry, unsigned char *e_ident)
{
printf("  Entry point address:               ");
if (e_ident[EI_DATA] == ELFDATA2MSB)
{
e_entry = ((e_entry << 8) & 0xFF00FF00) |
((e_entry >> 8) & 0xFF00FF);
e_entry = (e_entry << 16) | (e_entry >> 16);
}
if (e_ident[EI_CLASS] == ELFCLASS32)
printf("%#x\n", (unsigned int)e_entry);
else
printf("%#lx\n", e_entry);
}

/**
 * close_elf - A function that closes the file descriptor for the ELF file
 *@elf: The file descriptor to be closed
 *Return: Nothing
 */

void close_elf(int elf)
{
if (close(elf) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fp %d\n", elf);
exit(98);
}
}
