#include <cstdio>
constexpr char const *seg[] = {
		" * * *\n"
		"*     *\n"
		"*     *\n"
		"*     *\n"
		"\n"
		"*     *\n"
		"*     *\n"
		"*     *\n"
		" * * *\n",
		"\n"
		"      *\n"
		"      *\n"
		"      *\n"
		"\n"
		"      *\n"
		"      *\n"
		"      *\n",
		" * * *\n"
		"      *\n"
		"      *\n"
		"      *\n"
		" * * *\n"
		"*\n"
		"*\n"
		"*\n"
		" * * *\n",
		" * * *\n"
		"      *\n"
		"      *\n"
		"      *\n"
		" * * *\n"
		"      *\n"
		"      *\n"
		"      *\n"
		" * * *\n",
		"\n"
		"*     *\n"
		"*     *\n"
		"*     *\n"
		" * * *\n"
		"      *\n"
		"      *\n"
		"      *\n\n",
		" * * *\n"
		"*\n"
		"*\n"
		"*\n"
		" * * *\n"
		"      *\n"
		"      *\n"
		"      *\n"
		" * * *\n",
		" * * *\n"
		"*\n"
		"*\n"
		"*\n"
		" * * *\n"
		"*     *\n"
		"*     *\n"
		"*     *\n"
		" * * *\n",
		" * * *\n"
		"      *\n"
		"      *\n"
		"      *\n"
		"\n"
		"      *\n"
		"      *\n"
		"      *\n\n",
		" * * *\n"
		"*     *\n"
		"*     *\n"
		"*     *\n"
		" * * *\n"
		"*     *\n"
		"*     *\n"
		"*     *\n"
		" * * *\n",
		" * * *\n"
		"*     *\n"
		"*     *\n"
		"*     *\n"
		" * * *\n"
		"      *\n"
		"      *\n"
		"      *\n"
		" * * *\n"
};
int main() {
	int n; scanf("%d", &n); printf(seg[n]);
}