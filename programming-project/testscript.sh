make clean
make all
./pgmEcho
./pgmComp
./pgmReduce
./pgmb2a
./pgma2b
./pgmEcho bad argument count
./pgmEcho nonexistent.pgm out.pgm
./pgmEcho bad_magic_number.pgm out.pgm
./pgmEcho bad_comment_line.pgm out.pgm
./pgmEcho bad_dimensions_width.pgm out.pgm
./pgmEcho bad_dimensions_height.pgm out.pgm
./pgmEcho bad_max_gray.pgm out.pgm
./pgmEcho slice0a.pgm out.pgm
./pgmComp bad argument count
./pgmComp nonexistent.pgm out.pgm
./pgmComp bad_magic_number.pgm out.pgm
./pgmComp bad_comment_line.pgm out.pgm
./pgmComp bad_dimensions_width.pgm out.pgm
./pgmComp bad_dimensions_height.pgm out.pgm
./pgmComp bad_max_gray.pgm out.pgm
./pgmComp ascii_pgm_example.pgm ascii_pgm_example_copy.pgm
./pgmComp ascii_pgm_example.pgm binary_pgm_example.pgm
./pgmComp binary_pgm_example.pgm ascii_pgm_example.pgm
./pgma2b bad argument count
./pgma2b nonexistent.pgm out.pgm
./pgma2b bad_magic_number.pgm out.pgm
./pgma2b bad_comment_line.pgm out.pgm
./pgma2b bad_dimensions_width.pgm out.pgm
./pgma2b bad_dimensions_height.pgm out.pgm
./pgma2b bad_max_gray.pgm out.pgm
./pgma2b ascii_pgm_example.pgm ascii_example_to_binary.pgm
./pgmb2a bad argument count
./pgmb2a nonexistent.pgm out.pgm
./pgmb2a bad_magic_number.pgm out.pgm
./pgmb2a bad_comment_line.pgm out.pgm
./pgmb2a bad_dimensions_width.pgm out.pgm
./pgmb2a bad_dimensions_height.pgm out.pgm
./pgmb2a bad_max_gray.pgm out.pgm
./pgmb2a binary_pgm_example.pgm binary_example_to_ASCII.pgm
./pgmReduce bad argument count count
./pgmReduce nonexistent.pgm 2 out.pgm
./pgmReduce bad_magic_number.pgm 2 out.pgm
./pgmReduce bad_comment_line.pgm 2 out.pgm
./pgmReduce bad_dimensions_width.pgm 2 out.pgm
./pgmReduce bad_dimensions_height.pgm 2 out.pgm
./pgmReduce bad_max_gray.pgm 2 out.pgm
./pgmReduce ascii_pgm_example.pgm 2 reduced_by_2.pgm
./pgmReduce ascii_pgm_example.pgm 5 reduced_by_5.pgm
./pgmReduce ascii_pgm_example.pgm 10 reduced_by_10.pgm
./pgmEcho bad_data.pgm out.pgm
./pgmComp bad_data.pgm out.pgm
./pgmReduce bad_data.pgm 2 out.pgm
./pgmb2a bad_data.pgm out.pgm
./pgma2b bad_data.pgm out.pgm
 


