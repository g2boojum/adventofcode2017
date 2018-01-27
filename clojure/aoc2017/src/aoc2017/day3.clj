(ns aoc2017.day3
  (:require [clojure.math.numeric-tower :as math]))

(defn perimeter-size
  [j]
  (if (= 0 j)
    1
    (* 8 j)))

(defn perimeter-side
  [j]
  (+ (* 2 j) 1))

(defn first-num-in-perimeter
  [j]
  (if (= 0 j)
    1
    (+ 1 (math/expt (- (* 2 j) 1) 2))))

(defn manhattan-distance-to-origin
  [a b]
  (+ (math/abs a) (math/abs b)))

(def step-dirs {0 [+1 0]
                90 [0 +1]
                180 [-1 0]
                270 [0 -1]})

(defn step
  [i x y ang perimeter steps-to-next-perimeter steps-to-next-turn]
  (let [[dx dy] (step-dirs ang)
        new-perim? (= 0 steps-to-next-perimeter)
        np (if new-perim? (inc perimeter) perimeter)
        nsteps-p (if new-perim? 
                   (perimeter-size np) 
                   (dec steps-to-next-perimeter))
        nsteps-turn (if (= 0 steps-to-next-turn)
                      (perimeter-side np)
                      (dec steps-to-next-turn))]
    [(inc i)
     (+ x dx)
     (+ y dy)
     np nsteps-p nsteps-turn]))

;; In the above, what I want to do is iterate steps. The problem is 
;; that right now the nsteps-turn logic isn't correct. That
;; should probably be its own function based on [i perimeter ang].


