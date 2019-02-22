# qt-ts-csv
A tool to generate csv and xlsx file from qt ts file and vice versa

## Build
I used qmake systems and QtCreator as IDE.  
The build directory have to be on the same lavel as the repo one.
The build directoy have to be named "build-qt-ts-csv".

## Use
Launch the program "qt-ts-csv.exe".  
Click the button "Source file"
and select the source file in the Filedialog 
(supported extentions: .ts, .xlsx, .csv).  
Click the button "Destination file" 
and select the destination file in the FileDialog 
	(supported extentions: .ts, .xlsx, .csv).  
Otherwise 
	click the button "Destination Forder"
	and select the destination folder in the FolderDialog 
		(default folder is is "Desktop") 
	and the extention of your output in the ComboBox
		(supported extentions: .ts, .xlsx, .csv).  
At last click the button "Convert".  
	If the extensions are supported the conversion should be 
	succesfully terminated. 

## Example
To generate output.csv  
![example conversion ts to csv](./doc/ts2csv.png)  
To generate output.xlsx  
![example conversion ts to xlsx](./doc/ts2xlsx.png)  
To generate output.ts  
![example conversion csv to ts](./doc/csv2ts.png)  
![example conversion xlsx to ts](./doc/xlsx2ts.png)  
