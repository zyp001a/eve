<Basic
a[0] = 1
a[0].Name = "name a[0]"
a[1] = 2
a[1].Name = "name a[1]"
^a[0] = ^ a[0].Print ^
^
for a {
^-I =  ^&-I.Print^
-i=    ^&-i.Print^
-I.Name=^&-I.Name.Print^
-N[0]= ^&-N[0].Print^
^
}
if !a[0] {
^!a[0]
^
} else if !a[1] {
^!a[1]
^
} else {
^a[0] && a[1]
^
} 
^CheckDone ^
a[0].Print.CheckDone
a[1].Print.CheckDone
^
^

>t/Basic.Output
^out
^
>stdout