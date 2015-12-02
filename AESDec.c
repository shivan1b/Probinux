/*
 * Created by Shivani Bhardwaj <shivanib134@gmail.com>
 *
 * Copyrights : Creator does not hold any copyrights to the
 * libraries and AES code used here. They have been taken from open
 * source codes available
 */

/*
 * Description
 * -----------
 * This code decrypts the dictionary so that root user is
 * able to add/delete any process to/from the list of reliable processes
 */

/*
 * Scope
 * -----
 * This code is partially functional for reading a CipherText file
 * and decrypting it. Full functionality can be achieved by correcting
 * the padding bits used for AES. They generate extra random characters
 * to the output
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Download MCrypt here
 * http://sourceforge.net/projects/mcrypt/
 */

#include <mcrypt.h>

#include <math.h>
#include <stdint.h>
#include <stdlib.h>

int decrypt(void* buffer, int buffer_len, char* IV,
    char* key, int key_len)
{
  	MCRYPT td = mcrypt_module_open("rijndael-128", NULL, "cbc", NULL);
  	int blocksize = mcrypt_enc_get_block_size(td);
  	
	if( buffer_len % blocksize != 0 )
		return 1;

  	mcrypt_generic_init(td, key, key_len, IV);
  	mdecrypt_generic(td, buffer, buffer_len);
  	mcrypt_generic_deinit (td);
  	mcrypt_module_close(td);

  	return 0;
}

int main()
{
  	MCRYPT td, td2;
	FILE * fpr;
        FILE * fpw;
  	char * ciphertext;
	size_t len = 0;
        ssize_t read;

  	char* IV = "AAAAAAAAAAAAAAAA";
  	char *key = "0123456789abcdef";
  	int keysize = 16; 			/* 128 bits */
  	char* buffer;
  	int buffer_len = 16;

	system("touch .dictionary");	
	fpr = fopen("dictionary", "r");
        fpw = fopen(".dictionary", "w");

        if(fpr == NULL)
                exit(EXIT_FAILURE);

        while((read = getline(&ciphertext, &len, fpr)) != -1)
        {

  		buffer = calloc(1, buffer_len);
  		strncpy(buffer, ciphertext, buffer_len);

  		decrypt(buffer, buffer_len, IV, key, keysize);
		fprintf(fpw, "%s\n", buffer);
	}

	system("rm dictionary");
	system("mv .dictionary dictionary");

  	return 0;
}
