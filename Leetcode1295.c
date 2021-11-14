void _start(){	
	int numsSize = 7;
	int ans = 0;
	int nums[] = {12,345,2,6,7896,1212,12345};

    for(int i = 0 ; i < numsSize ; ++i){
        int j = 0;
        int tmp = nums[i];
        while(tmp > 9){
            //tmp /= 10;
           	int q,r;
           	q = (tmp>>1)+(tmp>>2);
           	q = q+(q>>4);
           	q = q+(q>>8);
           	q = q+(q>>16);
			q = q >> 3;
			r = tmp-(((q<<2)+q) << 1);
			tmp = q + (r>9);
            j ++;
        }
        j ++;
        if( j % 2 == 0){
            ans ++;
        }
    }
    
    volatile char *tx = (volatile char*)0x40002000;
    *tx = (char)((ans + '0'));
    *tx = '\n';
}
