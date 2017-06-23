(defun power (x n)
	"Calculates x to the n-th power, where n >= 0 integer."
	"Complexity: O(logn)"
	(cond ((= n 0) 1)
		((evenp n) (expt (power x (/ n 2)) 2))
		(t (* x (power x (- n 1))))
	)
)
