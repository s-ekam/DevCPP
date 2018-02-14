//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
////				To FInd Max of a Vector
////int main() {
////    
//////    vector<int> vec;
//////    vec.push_back(5);
//////    vec.push_back(9);
//////    vec.push_back(7);
//////    cout<<*max_element(vec.begin(),vec.end());
////    for(int i=0;i<5 ;i++)
////    {
////    	for(int j=0;j<5;j++)
////    	{
////    		if(j==3)
////    			continue;
////    		cout<<i<<"  ";
////		}
////		cout<<endl;
////	}
////    
////	return 0;
////}
//
//
//
//
//
//int main() {
//    int t;
//    cin>>t;
//    while(t--)
//    {
//        int n,m,p=0,q=1,max=0,c=0,swp,max2=0;
//        cin>>n>>m;
//        int a[n+5][m+5][2]={0};
//        vector<int> vec;
//        for(int i=0;i<n;i++)
//        {
//            for(int j=0;j<m;j++)
//            {
//                cin>>a[i][j][p];
//                a[i][j][q]=a[i][j][p];
//                if(a[i][j][p]>max2)
//                {
//                    max2=a[i][j][p];
//                    c++;
////                    cout<<" max  "<<max2<<endl;
//                }
//            }
//        }
//        if(c==1)
//        {
//            cout<<0<<endl;
//            continue;
//        }
//        int flag=1;
//        c=0;
//        while(flag)
//        {
//            flag=0;
//            for(int i=0;i<n;i++)
//            {
//            	for(int j=0;j<m;j++)
//                {
//                	vec.clear();
//                	if(a[i][j][p]==max2)
//                    {
//                        a[i][j][q]=max2;
//                        continue;
//                    }
//                    if(n==1)
//                    {
//                    	if(j==0)
//                    	{
//                    		vec.push_back(a[i][j][p]);
//                            vec.push_back(a[i][j+1][p]);
//                            max=*max_element(vec.begin(),vec.end());
//                            if(max>a[i][j][p])
//                            {
//                                a[i][j][q]=max;
//                                flag=1;
//                            }
//                            continue;
//						}
//						if(j==m-1)
//						{
//							vec.push_back(a[i][j][p]);
//                            vec.push_back(a[i][j-1][p]);
//                            max=*max_element(vec.begin(),vec.end());
//                            if(max>a[i][j][p])
//                            {
//                                a[i][j][q]=max;
//                                flag=1;
//                            }
//                            continue;
//						}
//						else
//						{
//							vec.push_back(a[i][j][p]);
//                            vec.push_back(a[i][j+1][p]);
//                            vec.push_back(a[i][j-1][p]);
//                            max=*max_element(vec.begin(),vec.end());
//                            if(max>a[i][j][p])
//                            {
//                                a[i][j][q]=max;
//                                flag=1;
//                            }
//                            continue;
//						}
//					}
//					if(m==1)
//					{
//						if(i==0)
//						{
//							vec.push_back(a[i][j][p]);
//                            vec.push_back(a[i+1][j][p]);
//                            max=*max_element(vec.begin(),vec.end());
//                            if(max>a[i][j][p])
//                            {
//                                a[i][j][q]=max;
//                                flag=1;
//                            }
//                            continue;
//						}
//						if(i==n-1)
//						{
//							vec.push_back(a[i][j][p]);
//                            vec.push_back(a[i-1][j][p]);
//                            max=*max_element(vec.begin(),vec.end());
//                            if(max>a[i][j][p])
//                            {
//                                a[i][j][q]=max;
//                                flag=1;
//                            }
//                            continue;
//						}
//						else
//						{
//							vec.push_back(a[i][j][p]);
//                            vec.push_back(a[i+1][j][p]);
//                            vec.push_back(a[i-1][j][p]);
//                            max=*max_element(vec.begin(),vec.end());
//                            if(max>a[i][j][p])
//                            {
//                                a[i][j][q]=max;
//                                flag=1;
//                            }
//                            continue;
//						}
//					}
//                    if(i==0)
//                    {
//                        if(j==0)
//                        {
//                            vec.push_back(a[i][j][p]);
//                            vec.push_back(a[i][j+1][p]);
//                            vec.push_back(a[i+1][j][p]);
//                            vec.push_back(a[i+1][j+1][p]);
//                            max=*max_element(vec.begin(),vec.end());
//                            if(max>a[i][j][p])
//                            {
//                                a[i][j][q]=max;
//                                flag=1;
//                            }
//                            continue;
//                        }
//                        else if(j==n-1)
//                        {
//                        	vec.push_back(a[i][j][p]);
//                            vec.push_back(a[i][j-1][p]);
//                            vec.push_back(a[i+1][j][p]);
//                            vec.push_back(a[i+1][j-1][p]);
//                            a[i][j][q]=*max_element(vec.begin(),vec.end());
//                            if(max>a[i][j][p])
//                            {
//                                a[i][j][q]=max;
//                                flag=1;
//                            }
//                            continue;
//                        	
//						}
//                        else
//                        {
//                            vec.push_back(a[i][j][p]);
//                            vec.push_back(a[i][j+1][p]);
//                            vec.push_back(a[i][j-1][p]);
//                            vec.push_back(a[i+1][j][p]);
//                            vec.push_back(a[i+1][j+1][p]);
//                            vec.push_back(a[i+1][j-1][p]);
//                            a[i][j][q]=*max_element(vec.begin(),vec.end());
//                            if(max>a[i][j][p])
//                            {
//                                a[i][j][q]=max;
//                                flag=1;
//                            }
//                            continue;
//                        }
//                        
//                    }
//                    if(i==(n-1))
//                    {
//                        if(j==(n-1))
//                        {
//                            vec.push_back(a[i][j][p]);
//                            vec.push_back(a[i][j-1][p]);
//                            vec.push_back(a[i-1][j][p]);
//                            vec.push_back(a[i-1][j-1][p]);
//                            max=*max_element(vec.begin(),vec.end());
//                            if(max>a[i][j][p])
//                            {
//                                a[i][j][q]=max;
//                                flag=1;
//                            }
//                            continue;
//                        }
//                        if(j==0)
//                        {
//                        	vec.push_back(a[i][j][p]);
//                            vec.push_back(a[i][j+1][p]);
//                            vec.push_back(a[i-1][j][p]);
//                            vec.push_back(a[i-1][j+1][p]);
//                            max=*max_element(vec.begin(),vec.end());
//                            if(max>a[i][j][q])
//                            {
//                                a[i][j][q]=max;
//                                flag=1;
//                            }
//                            continue;
//						}
//                        else
//                        {
//                            vec.push_back(a[i][j][p]);
//                            vec.push_back(a[i][j+1][p]);
//                            vec.push_back(a[i-1][j+1][p]);
//                            vec.push_back(a[i][j-1][p]);
//                            vec.push_back(a[i-1][j][p]);
//                            vec.push_back(a[i-1][j-1][p]);
//                            max=*max_element(vec.begin(),vec.end());
//                            if(max>a[i][j][p])
//                            {
//                                a[i][j][q]=max;
//                                flag=1;
//                            }
//                            continue;
//                        }
//                    }
//                    
//                    if(j==0)
//                    {
//                        vec.push_back(a[i][j][p]);
//                        vec.push_back(a[i-1][j][p]);
//                        vec.push_back(a[i+1][j][p]);
//                        vec.push_back(a[i][j+1][p]);
//                        vec.push_back(a[i-1][j+1][p]);
//                        vec.push_back(a[i+1][j+1][p]);
//                        max=*max_element(vec.begin(),vec.end());
//                        if(max>a[i][j][p])
//                        {
//                            a[i][j][q]=max;
//                            flag=1;
//                        }
//                        continue;
//                    }
//                    
//					if(j==(n-1))
//                    {
//                        vec.push_back(a[i][j][p]);
//                        vec.push_back(a[i+1][j][p]);
//                        vec.push_back(a[i-1][j][p]);
//                        vec.push_back(a[i][j-1][p]);
//                        vec.push_back(a[i+1][j-1][p]);
//                        vec.push_back(a[i-1][j-1][p]);
//                        max=*max_element(vec.begin(),vec.end());
//                        if(max>a[i][j][p])
//                        {
//                            a[i][j][q]=max;
//                            flag=1;
//                        }
//                        continue;
//                    }
//                    else
//                    {
//                        vec.push_back(a[i][j][p]);
//                        vec.push_back(a[i-1][j][p]);
//                        vec.push_back(a[i+1][j][p]);
//                        vec.push_back(a[i][j+1][p]);
//                        vec.push_back(a[i-1][j+1][p]);
//                        vec.push_back(a[i+1][j+1][p]);
//                        vec.push_back(a[i][j-1][p]);
//                        vec.push_back(a[i-1][j-1][p]);
//                        vec.push_back(a[i+1][j-1][p]);
//                        max=*max_element(vec.begin(),vec.end());
//                        if(max>a[i][j][p])
//                        {
//                            a[i][j][q]=max;
//                            flag=1;
//                        }
//                        continue;
//                    }
//                }
//            }
//            if(flag)
//	        {
//			   swp=p;
//	            p=q;
//	            q=swp;
//	            c++;
//	        }
//        }
//        cout<<c<<endl;
//   }
//	return 0;
//}



