#include "rectangle.h"
#include "term.h"
#include "group.h"
#include<iostream>

using namespace std;

//複製陣列之函式
void copy( term* termarr, int terms, term* temp )//copy the type of term(array)
{
    for( int ca=0; ca<terms; ca++ )
    {
        temp[ca]=termarr[ca];
    }
}

//class rectangle 建構，解構子
rectangle::rectangle( int num = 0 ):capacity( num )
{
    terms = 0;
    termarr = new term [ capacity+1 ];//新增原始陣列
    termarr_left = new term [ capacity+1 ];//新增左邊界排序陣列
    termarr_right = new term [ capacity+1 ];//新增右邊界排序陣列
    termarr_top = new term [ capacity+1 ];//新增上邊界排序陣列
    termarr_bottom = new term [ capacity+1 ];//新增下邊界排序陣列
}
rectangle::~rectangle()
{

}


//以左邊界排序之函式
void rectangle::copy_left_f()//sorting by left edge
{
    int hold_left=0;
    int hold_right=0;
    int hold_top=0;
    int hold_bottom=0;
    int hold_initial=0;

//bubble sort 排序
    for( int i=0; i<terms; i++ )
    {
        for( int j=0; j<terms-1; j++)
        {
            if( termarr_left[j].left>termarr_left[j+1].left )
            {
                hold_left = termarr_left[j].left;
                hold_right = termarr_left[j].right;
                hold_top = termarr_left[j].top;
                hold_bottom = termarr_left[j].bottom;
                hold_initial = termarr_left[j].initial;

                termarr_left[j].left = termarr_left[j+1].left;
                termarr_left[j].right = termarr_left[j+1].right;
                termarr_left[j].top = termarr_left[j+1].top;
                termarr_left[j].bottom = termarr_left[j+1].bottom;
                termarr_left[j].initial = termarr_left[j+1].initial;

                termarr_left[j+1].left = hold_left;
                termarr_left[j+1].right = hold_right;
                termarr_left[j+1].top = hold_top;
                termarr_left[j+1].bottom = hold_bottom;
                termarr_left[j+1].initial = hold_initial;
            }
        }
    }
//將號碼牌發給每一個陣列的 left_f
    for( int t=0; t<terms; t++)
    {
        termarr_left[t].left_f=t;
        termarr_right[t].left_f=t;
        termarr_top[t].left_f=t;
        termarr_right[t].left_f=t;
    }
}

//以左邊界排序之函式

//以右邊界排序之函式
void rectangle::copy_right_f()
{
    int hold_left=0;
    int hold_right=0;
    int hold_top=0;
    int hold_bottom=0;
    int hold_initial=0;

    for( int i=0; i<terms; i++ )
    {
        for( int j=0; j<terms-1; j++)
        {
            if( termarr_right[j].right>termarr_right[j+1].right )
            {

                hold_left = termarr_right[j].left;
                hold_right = termarr_right[j].right;
                hold_top = termarr_right[j].top;
                hold_bottom = termarr_right[j].bottom;
                hold_initial = termarr_right[j].initial;

                termarr_right[j].left = termarr_right[j+1].left;
                termarr_right[j].right = termarr_right[j+1].right;
                termarr_right[j].top = termarr_right[j+1].top;
                termarr_right[j].bottom = termarr_right[j+1].bottom;
                termarr_right[j].initial = termarr_right[j+1].initial;

                termarr_right[j+1].left = hold_left;
                termarr_right[j+1].right = hold_right;
                termarr_right[j+1].top = hold_top;
                termarr_right[j+1].bottom = hold_bottom;
                termarr_right[j+1].initial = hold_initial;
            }
        }
    }
    for( int t=0; t<terms; t++)
    {
        termarr_right[t].right_f=t;
        termarr_left[t].right_f=t;
        termarr_top[t].right_f=t;
        termarr_bottom[t].right_f=t;
    }
}

//以上邊界排序之函式
void rectangle::copy_top_f()
{
    int hold_left=0;
    int hold_right=0;
    int hold_top=0;
    int hold_bottom=0;
    int hold_initial=0;

    for( int i=0; i<terms; i++ )
    {
        for( int j=0; j<terms-1; j++)
        {
            if( termarr_top[j].top>termarr_top[j+1].top )
            {

                hold_left = termarr_top[j].left;
                hold_right = termarr_top[j].right;
                hold_top = termarr_top[j].top;
                hold_bottom = termarr_top[j].bottom;
                hold_initial = termarr_top[j].initial;

                termarr_top[j].left = termarr_top[j+1].left;
                termarr_top[j].right = termarr_top[j+1].right;
                termarr_top[j].top = termarr_top[j+1].top;
                termarr_top[j].bottom = termarr_top[j+1].bottom;
                termarr_top[j].initial = termarr_top[j+1].initial;

                termarr_top[j+1].left = hold_left;
                termarr_top[j+1].right = hold_right;
                termarr_top[j+1].top = hold_top;
                termarr_top[j+1].bottom = hold_bottom;
                termarr_top[j+1].initial = hold_initial;
            }
        }
    }
    for( int t=0; t<terms; t++)
    {
        termarr_right[t].top_f=t;
        termarr_left[t].top_f=t;
        termarr_top[t].top_f=t;
        termarr_bottom[t].top_f=t;
    }
}
//以上邊界排序之函式

//以下邊界排序之函式
void rectangle::copy_bottom_f()
{
    int hold_left=0;
    int hold_right=0;
    int hold_top=0;
    int hold_bottom=0;
    int hold_initial=0;

    for( int i=0; i<terms; i++ )
    {
        for( int j=0; j<terms-1; j++)
        {
            if( termarr_bottom[j].bottom>termarr_bottom[j+1].bottom )
            {

                hold_left = termarr_bottom[j].left;
                hold_right = termarr_bottom[j].right;
                hold_top = termarr_bottom[j].top;
                hold_bottom = termarr_bottom[j].bottom;
                hold_initial = termarr_bottom[j].initial;

                termarr_bottom[j].left = termarr_bottom[j+1].left;
                termarr_bottom[j].right = termarr_bottom[j+1].right;
                termarr_bottom[j].top = termarr_bottom[j+1].top;
                termarr_bottom[j].bottom = termarr_bottom[j+1].bottom;
                termarr_bottom[j].initial = termarr_bottom[j+1].initial;

                termarr_bottom[j+1].left = hold_left;
                termarr_bottom[j+1].right = hold_right;
                termarr_bottom[j+1].top = hold_top;
                termarr_bottom[j+1].bottom = hold_bottom;
                termarr_bottom[j+1].initial = hold_initial;
            }
        }
    }
    for( int t=0; t<terms; t++)
    {
        termarr_right[t].bottom_f=t;
        termarr_left[t].bottom_f=t;
        termarr_top[t].bottom_f=t;
        termarr_bottom[t].bottom_f=t;
    }
}
//以下邊界排序之函式

//新增一個矩形的位子之函式
void rectangle::newterm( const int newtop, const int newbottom, const int newleft, const int newright )
{
    //若陣列的空間不足，則將空間擴充成現在的兩倍
    if( terms==capacity )
    {
        capacity*=2;
        term *temp = new term[ capacity ];////////////////////暫時儲存原始陣列的陣列
        term *temp_left = new term[ capacity ];///////////////暫時儲存以左邊界排序陣列的陣列
        term *temp_right = new term[ capacity ];//////////////暫時儲存以右邊界排序陣列的陣列
        term *temp_bottom = new term[ capacity ];/////////////暫時儲存以下邊界排序陣列的陣列
        term *temp_top = new term[ capacity ];////////////////暫時儲存以上邊界排序陣列的陣列
        copy( termarr,terms,temp);//////////////////////////複製陣列進暫存存的陣列
        copy( termarr_left,terms,temp_left);
        copy( termarr_right,terms,temp_right);
        copy( termarr_top,terms,temp_top);
        copy( termarr_bottom,terms,temp_bottom);
        delete [] termarr;///////////////////////////////////將原始陣列清空
        delete [] termarr_left;
        delete [] termarr_top;
        delete [] termarr_right;
        delete [] termarr_bottom;
        termarr=temp;////////////////////////////////////////將原始陣列指向暫站存的陣列
        termarr_left=temp_left;
        termarr_right=temp_right;
        termarr_top=temp_top;
        termarr_bottom=temp_bottom;
    }
    /////////////////////////////////////若陣列的空間不足，則將空間擴充成現在的兩倍//////////////////////////////////////

    /////////////////////////////////////將讀到的矩陣資料存進去 /////////////////////////////////////////////////////////
    termarr[terms].top = newtop;
    termarr[terms].bottom = newbottom;
    termarr[terms].left = newleft;
    termarr[terms].right = newright;
    termarr[terms].initial = terms;
    /////////////////////////////////////將讀到的矩陣資料存進去 /////////////////////////////////////////////////////////

    termarr_left[terms].top = newtop;
    termarr_left[terms].bottom = newbottom;
    termarr_left[terms].left = newleft;
    termarr_left[terms].right = newright;
    termarr_left[terms].initial = terms;

    termarr_top[terms].top = newtop;
    termarr_top[terms].bottom = newbottom;
    termarr_top[terms].left = newleft;
    termarr_top[terms].right = newright;
    termarr_top[terms].initial = terms;

    termarr_bottom[terms].top = newtop;
    termarr_bottom[terms].bottom = newbottom;
    termarr_bottom[terms].left = newleft;
    termarr_bottom[terms].right = newright;
    termarr_bottom[terms].initial = terms;

    termarr_right[terms].top = newtop;
    termarr_right[terms].bottom = newbottom;
    termarr_right[terms].left = newleft;
    termarr_right[terms].right = newright;
    termarr_right[terms].initial = terms;

    terms++;
}
///////////////////////////////////新增一個矩形的位子之函式//////////////////////////////////////////////////////////////

///////////////////////////////////列印原始數據之函式////////////////////////////////////////////////////////////////////
void rectangle::print()//output the result of sorting by origin
{
    cout<<"Print initial:"<<endl;
    for( int c = 0; c<terms; c++ )
    {
        cout<<"The "<<termarr_left[c].initial+1<<"'s top is "<<termarr[termarr_left[c].initial].top<<endl;
        //////////////termarr_*****[c].initial 為原始數據之號碼

        cout<<"The "<<termarr_left[c].initial+1<<"'s bottom is "<<termarr[termarr_left[c].initial].bottom<<endl;
        cout<<"The "<<termarr_left[c].initial+1<<"'s left is "<<termarr[termarr_left[c].initial].left<<endl;
        cout<<"The "<<termarr_left[c].initial+1<<"'s right is "<<termarr[termarr_left[c].initial].right<<endl;
        cout << endl;
    }
    cout << endl;
}
///////////////////////////////////列印原始數據之函式////////////////////////////////////////////////////////////////////


///////////////////////////////////列印以左邊界排序之函式////////////////////////////////////////////////////////////////
void rectangle::print_left_f()//output the result of sorting by left edge
{
    cout<<"Print left first:"<<endl;
    for( int p=0; p<terms; p++)
    {
        cout<<"The "<<termarr_left[p].left_f+1<<"'s top is "<<termarr_left[termarr_left[p].left_f].top<<endl;
        //////////////termarr_*****[p].left_f 為以左邊界排序之號碼
        //////////////*****可以代換成 left，right，top，bottom
        //////////////拿著這張號碼牌去以左邊界排序之陣列問是誰

        cout<<"The "<<termarr_left[p].left_f+1<<"'s bottom is "<<termarr_left[termarr_left[p].left_f].bottom<<endl;
        cout<<"The "<<termarr_left[p].left_f+1<<"'s left is "<<termarr_left[termarr_left[p].left_f].left<<endl;
        cout<<"The "<<termarr_left[p].left_f+1<<"'s right is "<<termarr_left[termarr_left[p].left_f].right<<endl;
        cout<<"The "<<termarr_left[p].left_f+1<<"'s initial is "<<termarr_left[p].initial+1<<endl;
        ///////////////在原始陣列裡，你是第幾號

        cout << endl;
    }
    cout << endl;
    cout << endl;
}
///////////////////////////////////列印以左邊界排序之函式////////////////////////////////////////////////////////////////

///////////////////////////////////列印以右邊界排序之函式////////////////////////////////////////////////////////////////
void rectangle::print_right_f()//output the result of sorting by right edge
{
    cout<<"Print right first:"<<endl;
    for( int p=0; p<terms; p++)
    {
        cout<<"The "<<termarr_left[p].right_f+1<<"'s top is "<<termarr_right[termarr_left[p].right_f].top<<endl;
        //////////////termarr_*****[p].right_f 為以右邊界排序之號碼
        //////////////*****可以代換成 left，right，top，bottom
        //////////////拿著這張號碼牌去以右邊界排序之陣列問是誰

        cout<<"The "<<termarr_left[p].right_f+1<<"'s bottom is "<<termarr_right[termarr_left[p].right_f].bottom<<endl;
        cout<<"The "<<termarr_left[p].right_f+1<<"'s left is "<<termarr_right[termarr_left[p].right_f].left<<endl;
        cout<<"The "<<termarr_left[p].right_f+1<<"'s right is "<<termarr_right[termarr_left[p].right_f].right<<endl;
        cout<<"The "<<termarr_left[p].right_f+1<<"'s initial is "<<termarr_right[p].initial+1<<endl;
        cout << endl;
    }
    cout << endl;
    cout << endl;
}
///////////////////////////////////列印以右邊界排序之函式////////////////////////////////////////////////////////////////

///////////////////////////////////列印以上邊界排序之函式////////////////////////////////////////////////////////////////
void rectangle::print_top_f()//output the result of sorting by top edge
{
    cout<<"Print top first:"<<endl;
    for( int p=0; p<terms; p++)
    {
        cout<<"The "<<termarr_left[p].top_f+1<<"'s top is "<<termarr_top[termarr_left[p].top_f].top<<endl;
        //////////////termarr_*****[p].top_f 為以上邊界排序之號碼
        //////////////*****可以代換成 left，right，top，bottom
        //////////////拿著這張號碼牌去以上邊界排序之陣列問是誰

        cout<<"The "<<termarr_left[p].top_f+1<<"'s bottom is "<<termarr_top[termarr_left[p].top_f].bottom<<endl;
        cout<<"The "<<termarr_left[p].top_f+1<<"'s left is "<<termarr_top[termarr_left[p].top_f].left<<endl;
        cout<<"The "<<termarr_left[p].top_f+1<<"'s right is "<<termarr_top[termarr_left[p].top_f].right<<endl;
        cout<<"The "<<termarr_left[p].top_f+1<<"'s initial is "<<termarr_top[p].initial+1<<endl;
        cout << endl;
    }
    cout << endl;
    cout << endl;

}
///////////////////////////////////列印以上邊界排序之函式////////////////////////////////////////////////////////////////

///////////////////////////////////列印以下邊界排序之函式////////////////////////////////////////////////////////////////

void rectangle::print_bottom_f()//output the result of sorting by bottom edge
{
    cout<<"Print bottom first:"<<endl;
    for( int p=0; p<terms; p++)
    {
        cout<<"The "<<termarr_left[p].bottom_f+1<<"'s top is "<<termarr_bottom[termarr_left[p].bottom_f].top<<endl;
        //////////////termarr_*****[p].bottom_f 為以下邊界排序之號碼
        //////////////*****可以代換成 left，right，top，bottom
        //////////////拿著這張號碼牌去以下邊界排序之陣列問是誰

        cout<<"The "<<termarr_left[p].bottom_f+1<<"'s bottom is "<<termarr_bottom[termarr_left[p].bottom_f].bottom<<endl;
        cout<<"The "<<termarr_left[p].bottom_f+1<<"'s left is "<<termarr_bottom[termarr_left[p].bottom_f].left<<endl;
        cout<<"The "<<termarr_left[p].bottom_f+1<<"'s right is "<<termarr_bottom[termarr_left[p].bottom_f].right<<endl;
        cout<<"The "<<termarr_left[p].bottom_f+1<<"'s initial is "<<termarr_bottom[p].initial+1<<endl;
        cout << endl;
    }
    cout << endl;
    cout << endl;
}
///////////////////////////////////列印以下邊界排序之函式////////////////////////////////////////////////////////////////

void rectangle::x_group_print()//output the result of x single link
{
	for(int c=0;c<terms;c++ )
	{
		for( int i=0;i<termarr_left[termarr_left[c].left_f].x_next_terms;i++ )
		{
			cout<<"Shape(in initial) "<<termarr_left[termarr_left[c].left_f].initial+1<<" is group with "<<termarr_left[termarr_left[c].left_f].x_next[i]+1<<endl;
		}

	}

}

void rectangle::y_group_print()//output the result of y single link
{
	for(int c=0;c<terms;c++ )
	{
		for( int i=0;i<termarr_bottom[termarr_left[c].bottom_f].y_next_terms;i++ )
		{
			cout<<"Shape(in initial) "<<termarr_bottom[termarr_left[c].bottom_f].initial+1<<" is group with "<<termarr_bottom[termarr_left[c].bottom_f].y_next[i]+1<<endl;
		}

	}

}

void rectangle::x_grouping()//x single link
{

	for( int g=0;g<terms;g++ )
	{
	    //g是比較的shape
		int count=g+1;//count 為被比較的shape
		while( ( (termarr_left[termarr_left[count].left_f].left - termarr_left[termarr_left[g].left_f].right) < 50 )&&(count<terms) )
		{
			if( ((termarr_left[termarr_left[g].left_f].top) > (termarr_left[termarr_left[count].left_f].bottom)) && ((termarr_left[termarr_left[g].left_f].bottom) < (termarr_left[termarr_left[count].left_f].top)))
			{

			    // grouping
			    bool is_in_groups=0;
                for(int a=0;a<group::groups.size();a++){
                    if(group::groups[a]->is_in_group(&termarr_left[termarr_left[g].left_f])){
                        group::groups[a]->add(&termarr_left[termarr_left[count].left_f]);
                        //add term to group[a]

                        group::groups[a]->is_grouped(&termarr[termarr_left[termarr_left[count].left_f].initial]);
                        //set term if_grouped element to true by using group::is_grouped

                        is_in_groups = 1;
                        break;
                    }
                    if(group::groups[a]->is_in_group(&termarr_left[termarr_left[count].left_f])){
                        group::groups[a]->add(&termarr_left[termarr_left[g].left_f]);
                        //add term to group[a]

                        group::groups[a]->is_grouped(&termarr[termarr_left[termarr_left[g].left_f].initial]);
                        //set term if_grouped element to true by using group::is_grouped

                        is_in_groups = 1;
                        break;
                    }

                }

			    if(!is_in_groups){
                    group* new_group = new group;
                    group::groups.push_back(new_group);
                    group::groups.back()->add(&termarr_left[termarr_left[g].left_f]);
                    group::groups.back()->add(&termarr_left[termarr_left[count].left_f]);
                    //add terms to new group

                    group::groups.back()->is_grouped(&termarr[termarr_left[termarr_left[count].left_f].initial]);
                    group::groups.back()->is_grouped(&termarr[termarr_left[termarr_left[g].left_f].initial]);
                    //set terms if_grouped element to true by using group::is_grouped
			    }
			    //grouping [ok]


				termarr_left[termarr_left[g].left_f].x_next_newterm(termarr_left[termarr_left[count].left_f].initial);
				termarr_bottom[termarr_left[g].bottom_f].x_next_newterm(termarr_left[termarr_left[count].left_f].initial);
				termarr_right[termarr_left[g].right_f].x_next_newterm(termarr_left[termarr_left[count].left_f].initial);
				termarr_top[termarr_left[g].top_f].x_next_newterm(termarr_left[termarr_left[count].left_f].initial);
				count++;
			}
			else
			{
				count++;
			}
		}
	}
}

void rectangle::y_grouping()//y single link
{
    vector<group*> temp_groups;

	for( int g=0;g<terms;g++ )
	{
		int count=g+1;
		while( ( (termarr_bottom[termarr_left[count].bottom_f].bottom - termarr_bottom[termarr_left[g].bottom_f].top) < 100 )&&(count<terms) )
		{
			if( ((termarr_bottom[termarr_left[g].bottom_f].right) > (termarr_bottom[termarr_left[count].bottom_f].left)) && ((termarr_bottom[termarr_left[g].bottom_f].left) < (termarr_bottom[termarr_left[count].bottom_f].right)))
			{

                bool is_in_groups=0;
                //Merger x_groups && y_groups
                for(int a=0;a<group::groups.size();a++){
                        if(group::groups[a]->is_in_group(&termarr[termarr_bottom[termarr_left[g].bottom_f].initial])){ //is g shape in a group
                            group::groups[a]->add(&termarr[termarr_bottom[termarr_left[count].bottom_f].initial]);//add term to group[a]
                            group::groups[a]->is_grouped(&termarr[termarr_bottom[termarr_left[count].bottom_f].initial]);//set term if_grouped element to true by using group::is_grouped
                            is_in_groups=1;
                            break;
                        }
                        else if(group::groups[a]->is_in_group(&termarr[termarr_bottom[termarr_left[count].bottom_f].initial])){ //is [count] shape in a group
                            group::groups[a]->add(&termarr[termarr_bottom[termarr_left[g].bottom_f].initial]);//add [g] shape to group[a]
                            group::groups[a]->is_grouped(&termarr[termarr_bottom[termarr_left[g].bottom_f].initial]);//set term if_grouped element to true by using group::is_grouped
                            is_in_groups=1;
                            break;
                        }
                }

			    if(!is_in_groups){
                    group* new_group = new group;
                    group::groups.push_back(new_group);
                    group::groups.back()->add(&termarr[termarr_bottom[termarr_left[g].bottom_f].initial]);
                    group::groups.back()->add(&termarr[termarr_bottom[termarr_left[count].bottom_f].initial]);
                    //add terms to new group

                    group::groups.back()->is_grouped(&termarr[termarr_bottom[termarr_left[g].bottom_f].initial]);
                    group::groups.back()->is_grouped(&termarr[termarr_bottom[termarr_left[count].bottom_f].initial]);
                    //set terms if_grouped element to true by using group::is_grouped
                }

                //bean
                if(termarr[termarr_bottom[termarr_left[count].bottom_f].initial].if_grouped){//if already grouped
                    cout<<"abcde"<<endl;
                    if(termarr[termarr_bottom[termarr_left[count].bottom_f].initial].if_conflict){ //if conflict
                        cout<<"if add "<<group::In_which_group(&termarr[termarr_bottom[termarr_left[g].bottom_f].initial])+1<<" to "<<group::In_which_group(&termarr[termarr_bottom[termarr_left[count].bottom_f].initial])+1<<endl;
                        group::add_whole_group(group::In_which_group(&termarr[termarr_bottom[termarr_left[g].bottom_f].initial]),group::In_which_group(&termarr[termarr_bottom[termarr_left[count].bottom_f].initial]));
                        group::set_whole_conflict(group::In_which_group(&termarr[termarr_bottom[termarr_left[count].bottom_f].initial]));
                        group::set_whole_conflict(group::In_which_group(&termarr[termarr_bottom[termarr_left[g].bottom_f].initial]));
                        break;
                        }

                    else{
                        cout<<"else add groups["<<group::In_which_group(&termarr[termarr_bottom[termarr_left[g].bottom_f].initial])+1<<"] to groups["<<group::In_which_group(&termarr[termarr_bottom[termarr_left[count].bottom_f].initial])+1<<"]"<<endl;
                        cin.get();
                        if(group::In_which_group(&termarr[termarr_bottom[termarr_left[g].bottom_f].initial])==group::In_which_group(&termarr[termarr_bottom[termarr_left[count].bottom_f].initial]))break;
                        else{
                            cout<<"else add groups["<<group::In_which_group(&termarr[termarr_bottom[termarr_left[g].bottom_f].initial])+1<<"] to groups["<<group::In_which_group(&termarr[termarr_bottom[termarr_left[count].bottom_f].initial])+1<<"]"<<endl;
                            group::add_whole_group(group::In_which_group(&termarr[termarr_bottom[termarr_left[g].bottom_f].initial])+1,group::In_which_group(&termarr[termarr_bottom[termarr_left[count].bottom_f].initial])+1);
                            }
                        }
                }
                //bean

				termarr_left[termarr_left[g].left_f].y_next_newterm(termarr_bottom[termarr_left[count].bottom_f].initial);
				termarr_bottom[termarr_left[g].bottom_f].y_next_newterm(termarr_bottom[termarr_left[count].bottom_f].initial);
				termarr_right[termarr_left[g].right_f].y_next_newterm(termarr_bottom[termarr_left[count].bottom_f].initial);
				termarr_top[termarr_left[g].top_f].y_next_newterm(termarr_bottom[termarr_left[count].bottom_f].initial);
				count++;
			}
			else
			{
				count++;
			}
		}
	}


}

void rectangle::print_test_if_group()
{

    for( int t=0 ; t<terms; t++ )
    cout<<"termarr["<<t+1<<"].if_grouped is: "<<termarr[t].if_grouped<<endl;
    //print the result of if_grouped

}

void rectangle::print_test_if_conflict()
{

    for( int t=0 ; t<terms; t++ )
    cout<<"termarr["<<t+1<<"].if_conflict is: "<<termarr[t].if_conflict<<endl;
    //print the result of if_grouped

}
