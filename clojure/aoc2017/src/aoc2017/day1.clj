(ns aoc2017.day1)

(require '[clojure.core.rrb-vector :as fv])

(defn char-to-int
  [c]
  (- (int c) (int \0)))

(def digits "1254325")

(def digvec (fv/vec (map char-to-int digits)))

(fv/catvec digvec (fv/subvec digvec 0 1))
