=h
# Descriptions   : 
# Usage          : perl *.pl
# Parameters	 : none
# Sample Input   : 
# Sample Output  : 
# Depedency      : none
# Temp File      : none
# Comments       : none
# See Also       : none
# Data           : 
# Template       : Last modified date 11/16/10 
# Author         : setupX
=cut

use lib "/home/zyp/BioTools";
use Fatal qw(open close);
use Carp;
my $database="/home/func/database";
use IOfunc;
$dir=$ARGV[0];
$root_prefix = "backup$$";
if($dir =~ /([^\/\\]+)$/){
  $dira = $1;
}
else{
   die "wrong dir format $dir";
}
$root = "$root_prefix/$dira";
mkdir $root_prefix;
mkdir $root;

sub _expend{
	my $subdir=shift;
	mkdir "$root/$subdir";
	my $fp;
	open $fp,"ls -l $dir/$subdir |";
	while (<$fp>){
		chomp;
		@l=split /\s/;
		if(/^d/){
			&_expend("$subdir/$l[-1]");
		}
		else{
#			print "$l[-1]\n";
			if( $l[-1]=~/\.pl$/ ||
					$l[-1]=~/\.pm$/ ||
					$l[-1]=~/\.py$/ ||
					$l[-1]=~/\.c$/ ||
					$l[-1]=~/\.h$/ ||
					$l[-1]=~/\.R$/ ||
					$l[-1]=~/\.m$/ ||
					$l[-1]=~/\.sh$/ ||
					$l[-1]=~/\.e$/ ||
					$l[-1]=~/\.s\.tar$/ ||
					$l[-1]=~/README/ ||
					$l[-1]=~/DOWNLOAD/ ){
				system qq(cp $dir/$subdir/$l[-1] $root/$subdir/$l[-1]);
			}
		}
	}
}
open A,"ls -l $dir |";
while (<A>){
	chomp;
	@l=split /\s/;
	if(/^d/){
		&_expend("$l[-1]");
	}
	else{
		if( $l[-1]=~/\.pl$/ || 
				$l[-1]=~/\.pm$/ ||
				$l[-1]=~/\.py$/ ||
				$l[-1]=~/\.c$/ ||
				$l[-1]=~/\.R$/ ||
				$l[-1]=~/\.m$/ ||
				$l[-1]=~/\.sh$/ ||
				$l[-1]=~/\.s\.tar$/ ||
				$l[-1]=~/\.e$/ ||
				$l[-1]=~/README/ ||
				$l[-1]=~/DOWNLOAD/ ){
			system qq(cp $dir/$l[-1] $root/$l[-1]);
		}
	}
}
close A;
system qq(tar -c $root_prefix >$dir.s.tar);
system qq(rm $root_prefix -rf);
