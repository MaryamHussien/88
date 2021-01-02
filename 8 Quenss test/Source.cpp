#include<stdio.h>
#include<math.h>
#include<conio.h> 
#include<stdlib.h> 


List(int[]) solutions = new List(int[])()

if (denied != null)
{
    t.AddRange(denied);
}
row = item / 8;
column = item % 8;
rowmin = row * 8;
rowmax = rowmin + 7;
columnmin = column;
columnmax = column + 56;

//Left diagonal min and max...
leftdiagonalmin = item - Math.Min(row, column) * 9;
leftdiagonalmax = item + Math.Min(7 - row, 7 - column) * 9;

//Right diagonal min and max
rightdiagonalmin = item - Math.Min(row, 7 - column) * 7;
rightdiagonalmax = item + Math.Min(7 - row, column) * 7;

//Calculate the prohibited row fields from min to max, and adds to t (list)

for (int i = rowmin; i <= rowmax; i++)
{
    t.Add(i);
}

//Calculate the prohibited columns from min to max step by 8 and adds to t

for (int i = columnmin; i <= columnmax; i = i + 8)
{
    t.Add(i);
}

//Calculate the left diagonal from min to max step by 9 (8+1 same column and 1 field to right) 

for (int i = leftdiagonalmin; i <= leftdiagonalmax; i = i + 9)
{
    t.Add(i);
}

//Calculate to right diagonal from min to max step by 7 (8-1 same column and 1 field to left)

for (int i = rightdiagonalmin; i <= rightdiagonalmax; i = i + 7)
{
    t.Add(i);
}

//Calculate distinct : each fieldnumber can take part only one time. One field can be prohibited by more queens not only for one, but enough to mark this field only one 
List<int> tt = new List<int>();

tt = t.Distinct().ToList();

//Returns the new prohibited array, the original, and the new added.
return tt;
...



//Calculate the actual row min, and max values
rowmin = row * 8;
rowmax = rowmin + 7;

//If prohibited list is not null...
if (denied != null)
{

    //Loop through the row from min to max to each field
    for (int i = rowmin; i <= rowmax; i++)
    {
        //If the prohibited list NOT contains the field index, then add to list (will be returned)
        if (!denied.Contains(i))
        {
            t.Add(i);
        }

    }
}
//If prohibited list doesn't contain elements, then whole row is available (it can be happen only FIRST row)
else
{
    //Adds whole row from min to max to available fields list.
    for (int i = rowmin; i <= rowmax; i++)
    {
        t.Add(i);
    }
}

//REturns the available lists
return t;
...



//Black or white fields? blackwhite true means BLACK!
bool blackwhite = false;

//Nested loops to draw the chessboards. Calculates the position of pictures. Each chessboard fields have 70*70 size
for (int y = 0; y <= 7; y++)
{
    for (int x = 0; x <= 7; x++)
    {

        //Creates new Picturebox, sterched, with 70 pixel height and width
        PictureBox pb = new PictureBox();
        pb.SizeMode = PictureBoxSizeMode.StretchImage;
        pb.Height = 70;
        pb.Width = 70;


        //Calculates the position 1, 71,141 etc. 
        pb.Top = 1 + y * 70;
        pb.Left = 1 + x * 70;


        //If the field is black...then draw blac, else white
        if (blackwhite)
        {
            //Gets the picture from Program Resource. Resource can contain OBJECT, so we have to explicitely convert to Image
            pb.Image = (Image)Resources.ResourceManager.GetObject("black");

        }
        else
        {
            //Same if the field is white
            pb.Image = (Image)Resources.ResourceManager.GetObject("white");

        }

        //Adds the new control (picturebox) to Panel1 component
        panel1.Controls.Add(pb);

        //Change the blaxk or white flag
        blackwhite = !blackwhite;

    }
    //.. and here too, because in the beginning of a new row will NOT change the color. The last field, and a next row first field have the same color!
    blackwhite = !blackwhite;
}
...



...
//Occures when numeric we change the value of the updown controller

//Black or white flag, true means BLACK!
bool blackwhite = false;

//Local array: the solutio is a list of array of integer. This is an item of solutions!
int[] solution_item = new int[8];

//numeric updown index. The value is DECIMAL so we convert it to int.
int idx = Convert.ToInt32(numericUpDown1.Value);

//The idx-th element of solutions list is the local solution item.
solution_item = solutions[idx - 1];

//Converts the list to array => because .Contains method is very comfortable. (see below)
List<int> solution_item_list = solution_item.ToList();

//List of form controls This will be a list of pictureboxes on Panel1
List<Control> pbcontrollist = new List<Control>();

//Captures four images from Program Resource. The resource can contain object, so we convert it to Image
Image blackqueen = (Image)Resources.ResourceManager.GetObject("blackqueen");
Image whitequeen = (Image)Resources.ResourceManager.GetObject("whitequeen");
Image black = (Image)Resources.ResourceManager.GetObject("black");
Image white = (Image)Resources.ResourceManager.GetObject("white");

//Loop through the panel1 controls, and if it is picturebox, then adds to pbcontrollist
for (int ix = panel1.Controls.Count - 1; ix >= 0; ix--)
{
    if (panel1.Controls[ix] is PictureBox) { pbcontrollist.Add(panel1.Controls[ix]); }
}

//Loop through in all 64 fields of chessboard (0..63) and if local soution contains the number of field then draws a queen to chessboard. In other case it draws a simple field.
//Of course it have to calculate to black or white color as well.

for (int i = 0; i < 64; i++)
{
    //If local solution contains the number then QUEEN!
    if (solution_item_list.Contains(i))
    {
        //Black or White Queen?
        if (blackwhite)
        {
            //pbcontrollist[i] is a Control type, not a Picturebox. So we have to convert to Picturebox with "AS" 
            (pbcontrollist[i] as PictureBox).Image = blackqueen;
        }
        else
        {
            (pbcontrollist[i] as PictureBox).Image = whitequeen;
        }
    }
    ////If local solution does not containsthe number then simple field!
    else
    {
        if (blackwhite)
        {
            (pbcontrollist[i] as PictureBox).Image = black;
        }
        else
        {
            (pbcontrollist[i] as PictureBox).Image = white;
        }
    }

    //Problem:  after the last field of a row will NOT change the color (see a chessboard) It calculates the last field. If i is NOT index of a last-row field, then changes the color (black-white)

    int f = i / 8;

    //Not last field of a row? Then change...else NOT.
    if (i != (7 + 8 * f))
    {
        blackwhite = !blackwhite;
    }


}

            }
            //.. and here too, because in the beginning of a new row will NOT change the color. The last field, and a next row first field have the same color!
            blackwhite = !blackwhite;
            }
            ...
                ...



