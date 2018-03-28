#!/bin/sh

source_dir=$(cd $(dirname $0) && pwd)

for file in $(find "$source_dir" -maxdepth 2 -mindepth 2 -type f | grep '.cpp' ); do
        (
                cd "$(dirname $file)";
                mv $file $(dirname $file)/$(dirname $file | sed 's|.*/||g' | sed 's/^cpa_//g').cpp 2>/dev/null \
			&& { printf "%s" "$file" | sed 's|.*/||g'; echo " has been renamed."; } \
			|| { printf "%s" "$file" | sed 's|.*/||g'; echo " seems to be already correctly named.";  }
        )
done
