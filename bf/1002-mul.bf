,				read first digit
----- -----		convert first digit to null byte
----- -----
----- -----
----- -----
----- ---
> ,				read second digit
----- -----		convert second digit to null byte
----- -----
----- -----
----- -----
----- ---
<				move pointer to cell 0
[				enter loop
	>			move pointer to cell 1
	[			enter loop
		> +		move value to cell 2
		> +		move value to cell 3
		<< -	move pointer to cell 0
	]			exit loop
	>			move to cell 2
	[			enter loop
		< +		add value from cell 1 to cell 2
		> -		move pointer to cell 2
	]			exit loop
	<< -		move pointer to cell 0
]				exit loop
>>>
+++++ +++++		find ascii of result
+++++ +++++
+++++ +++++
+++++ +++++
+++++ +++
.				putchar result
