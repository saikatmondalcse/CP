struct Manacher{
	string t;
	vector<int>pi,odd,even;	
	Manacher(string &s)
	{
		t="";
	    for(char x:s){
	    	t+='#';
	    	t+=x;
	    }
	   	t+='#';
	    int n=t.length();
	    t='$'+t+'^';
	    pi.resize(n+2);
	    int l=0;
	    for(int i=1;i<=n;i++)
	    {
	    	if(l+pi[l]>=i)
		    	pi[i]=min(pi[2*l-i],l+pi[l]-i);
	    	pi[i]=max(0,pi[i]);

	    	while(t[i-pi[i]]==t[i+pi[i]])
	    		pi[i]++;
	    	if(i+pi[i]>l+pi[l])
	    		l=i;
	    }
	    for(int i=2;i<=n-1;i++)
	    {
	    	if(t[i]!='#')
	    		odd.pb(pi[i]/2);
	    	else
	    		even.pb((pi[i]-1)/2);
	    }
		
		// for odd length, characters will be at middle and for even length , # will be at middle
		// odd[i] -> s[i] character middle odd length
		// even[i] -> s[i] and s[i+1] character middle even length
	}

	bool checkpalindrome(int l,int r){
		bool flag=false;
        int len=r-l+1;
        int mid=(l+r)/2;
        if(len&1)
        {
            if(odd[mid]>=mid-l+1)
                flag=true;
        }
        else
        {
            if(even[mid]>=mid-l+1)
                flag=true;
        }
        return flag;
	}
};
