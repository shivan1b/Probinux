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
 * This code encrypts the dictionary so that not anybody is
 * able to add a process to the list of reliable processes
 * 
 */

/*
 * Scope
 * -----
 * This code is fully functional for reading a PlainText file
 * and encrypting it.
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

int encrypt(void* buffer,
    	int buffer_len, /* Because the plaintext could include null bytes*/
    	char* IV, char* key, int key_len)
{
  	MCRYPT td = mcrypt_module_open("rijndael-128", NULL, "cbc", NULL);
  	int blocksize = mcrypt_enc_get_block_size(td);

  	if( buffer_len % blocksize != 0 )
		return 1;

  	mcrypt_generic_init(td, key, key_len, IV);
  	mcrypt_generic(td, buffer, buffer_len);
  	mcrypt_generic_deinit (td);
 	mcrypt_module_close(td);
  
  	return 0;
}

int main()
{	
	MCRYPT td, td2;
	FILE * fpr;
	FILE * fpw;	

  	char * plaintext = NULL;
	size_t len = 0;
	ssize_t read;
  	char* IV = "AAAAAAAAAAAAAAAA";
  	char *key = "0123456789abcdef";
  	int keysize = 16; /* 128 bits */
  	char* buffer;
  	int buffer_len = 16;
	
	system("touch .dictionary");

	fpr = fopen("dictionary", "r");
	fpw = fopen(".dictionary", "w");

	if(fpr == NULL)
		exit(EXIT_FAILURE);
	
	while((read = getline(&plaintext, &len, fpr)) != -1)
	{
  		buffer = calloc(1, buffer_len);

  		strncpy(buffer, plaintext, buffer_len);
  		encrypt(buffer, buffer_len, IV, key, keysize);
		fprintf(fpw, "%s\n", buffer);
	}

	system("rm dictionary");
        system("mv .dictionary dictionary");

  	return 0;
}
